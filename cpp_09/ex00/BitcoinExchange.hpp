#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <string>
#include "Date.hpp"
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

	class InvalidDBPath : public std::exception
	{
		public:
			InvalidDBPath();
			const char *what()const throw(); 
			~InvalidDBPath() throw();
	};
};

#endif