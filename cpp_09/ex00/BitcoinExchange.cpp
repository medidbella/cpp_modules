#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

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
	std::stringstream FloatStream(line.c_str());
	FloatStream >> result;
	return result;
}

bool DateValidator(int *date)
{
	return (date[2] <= 31 && date[2] >= 1 && date[1] <= 12
		&& date[1] >= 1 && date[0] >= 0);
}

Date extractDate(std::string line)
{
	std::stringstream ss(line.c_str());
	int date[3];

	for (int i = 0; i < 3; i++)
	{
		std::getline(ss, line, '-');
		date[i] = std::atoi(line.c_str());
	}
	if (!DateValidator(date))
		throw (BitcoinExchange::InvalidInputException("invalid Date =>" + line));
	return Date(date[2], date[1], date[0]);
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

void BitcoinExchange::printAmountPrice(const std::string &inputLine) const
{
	float price;
	float amount = getPrice(inputLine, '|');
	if (amount > 100)
		throw BitcoinExchange::InvalidInputException("too large BTC amount");
	else if (amount < 0)
		throw BitcoinExchange::InvalidInputException("not a positive BTC amount");
	Date paymentDate = getDate(inputLine, '|');
	
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
