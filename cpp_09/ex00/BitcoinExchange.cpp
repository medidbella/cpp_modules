#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

bool DateValidator(int *date)
{
	return (date[2] <= 31 && date[2] >= 1 && date[1] <= 12
		&& date[1] >= 1 && date[0] >= 0);
}

Date extractDate(std::string line)
{
	std::stringstream ss(line.c_str());
	std::string words;
	int date[3];

	for (int i = 0; i < 3; i++)
	{
		std::getline(ss, words, '-');
		date[i] = std::atoi(words.c_str());
	}
	if (!DateValidator(date))
		throw (BitcoinExchange::InvalidInputException("invalid Date => " + line));
	return Date(date[2], date[1], date[0]);
}

Date getDate(std::string line, char separator)
{
	std::stringstream ss(line.c_str());
	std::getline(ss, line, separator);
	return extractDate(line);
}

float getPrice(std::string line, char separator)
{
	(void) line;
	float result  = 0;
	std::stringstream ss(line.c_str());
	std::getline(ss, line, separator);
	std::getline(ss, line, separator);
	unsigned int i = 0;
	if (line[0] == '-' || line[0] == '+')
		i += 1;
	while (i < line.length())
	{
		if ((!std::isdigit(line[i]) && line[i] != '.' && !std::isspace(line[i]))
			|| (line[i] == '.' && (i == 0 || i == line.size() - 1)))
		{
			throw BitcoinExchange::InvalidInputException("bad value syntax => " + line);
			break ;
		}
		i++;
	}
	std::stringstream floatStream(line.c_str());
	floatStream >> result;
	return result;
}

BitcoinExchange::BitcoinExchange(const std::string &DataBasePath)
{
	std::string line;
	std::ifstream DataBaseStream(DataBasePath.c_str());
	if (!DataBaseStream.is_open())
		throw BitcoinExchange::InvalidDBPathException();
	std::getline(DataBaseStream, line);
	while (!DataBaseStream.eof())
	{
		std::getline(DataBaseStream, line);
		if (!line.empty())
			PriceDataBase[getDate(line, ',')] = getPrice(line, ',');
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source){
	PriceDataBase = source.PriceDataBase;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &source){
	PriceDataBase = source.PriceDataBase;
	return *this;
}

void BitcoinExchange::printAmountPrice(const std::string &inputLine)
{
	Date initialDate;
	Date paymentDate;
	double TotalPrice = 0;
	float amount = 0;
	std::map<Date, float>::iterator lastElement = PriceDataBase.end();
	lastElement--;
	paymentDate = getDate(inputLine, '|');
	amount = getPrice(inputLine, '|');
	if (paymentDate < PriceDataBase.begin()->first)
		throw BitcoinExchange::InvalidInputException("payment date too old => " + inputLine);
	else if (lastElement->first < paymentDate){
		std::cout << paymentDate << " => " << amount << " = "
			<< lastElement->second * amount << '\n';
		return ;
	}
	if (amount > 1000)
		throw BitcoinExchange::InvalidInputException("too large BTC amount , amount range = <0, 1000>");
	else if (amount < 0)
		throw BitcoinExchange::InvalidInputException("not a positive BTC amount");
	initialDate = paymentDate;
	while (PriceDataBase.find(paymentDate) == PriceDataBase.end())
		--paymentDate;
	TotalPrice = static_cast<double>(amount) * PriceDataBase[paymentDate];
	std::cout << initialDate << " => " << amount << " = " << TotalPrice << '\n';
	return ;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::InvalidDBPathException::InvalidDBPathException(){}

const char *BitcoinExchange::InvalidDBPathException::what() const throw(){
	return "the provided DataBase is invalid or has no read permission";
}

BitcoinExchange::InvalidDBPathException::~InvalidDBPathException() throw(){}

BitcoinExchange::InvalidInputException::InvalidInputException(const std::string &error){
	errorMsg = error;
}

const char *BitcoinExchange::InvalidInputException::what() const throw(){
	return errorMsg.c_str();
}

BitcoinExchange::InvalidInputException::~InvalidInputException() throw(){}
