#include "BitcoinExchange.hpp"

int main(int Argc, char **Argv)
{
	std::string line;
	if (Argc != 2){
		std::cerr << "usage: ./btc <input_file.txt>\n"; return 1;}
	std::ifstream inputStream(Argv[1]);
	if (!inputStream.is_open()){
		std::cerr << "can't access " << Argv[1] << '\n' ; return 1;}
	BitcoinExchange btcExchangeSystem;
	try {
		btcExchangeSystem = BitcoinExchange("data.csv");
	}
	catch(std::exception &ex) {
		std::cout << "exception : \n" << ex.what() << '\n';
	}
	std::getline(inputStream, line);
	while (!inputStream.eof())
	{
		
		std::getline(inputStream, line);
		if (!line.empty())
		{
			try {
				btcExchangeSystem.printAmountPrice(line);
			}
			catch(std::exception &error) {
				std::cerr << "Error: " << error.what() << '\n';
			}
		}
	}
}
