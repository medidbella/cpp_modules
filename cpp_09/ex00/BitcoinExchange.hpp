#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include "Date.hpp"
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <exception>
#include <iostream>

class BitcoinExchange
{
	private:
		std::map<Date, float> PriceDataBase;
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &DataBasePath);
		BitcoinExchange(const BitcoinExchange &source);
		BitcoinExchange &operator=(const BitcoinExchange &source);
		void printAmountPrice(const std::string &inputLine) const;
		~BitcoinExchange();
		void printData()
		{
			std::map<Date, float>::iterator it = PriceDataBase.begin();
			for (unsigned int i = 0; i < PriceDataBase.size();i++)
			{
				if (i != 0)
					std::cout << it->first << "\t|\t" << it->second << '\n';
				it++;
			}
		}

	class InvalidDBPathException : public std::exception
	{
		public:
			InvalidDBPathException();
			const char *what()const throw();
			~InvalidDBPathException() throw();
	};

	class InvalidInputException : public std::exception
	{
		private:
			std::string errorMsg;
		public:
			InvalidInputException(const std::string &error);
			const char *what()const throw();
			~InvalidInputException() throw();
	};
};

#endif