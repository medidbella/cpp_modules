#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

Date getDate(std::string line)
{
	std::stringstream ss(line.c_str());
	std::getline(ss, line, ',');
	return extractDate(line);
}

float getPrice(std::string line)
{
	(void) line;
	float result  = 0;
	std::stringstream ss(line.c_str());
	std::getline(ss, line, ',');
	std::getline(ss, line, ',');
	std::stringstream FloatStream(line.c_str());
	FloatStream >> result;
	return result;
}

BitcoinExchange::BitcoinExchange(const std::string &DataBasePath)
{
	std::string line;
	std::ifstream DataBaseStream(DataBasePath.c_str());
	if (!DataBaseStream.is_open())
		throw BitcoinExchange::InvalidDBPath();
	std::getline(DataBaseStream, line);
	while (!DataBaseStream.eof())
	{
		std::getline(DataBaseStream, line);
		PriceDataBase[getDate(line)] = getPrice(line);
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source){
	PriceDataBase = source.PriceDataBase;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &source){
	PriceDataBase = source.PriceDataBase;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::InvalidDBPath::InvalidDBPath(){}

const char *BitcoinExchange::InvalidDBPath::what() const throw(){
	return "the provided DataBase is invalid or has no read permission";
}

BitcoinExchange::InvalidDBPath::~InvalidDBPath() throw(){}
