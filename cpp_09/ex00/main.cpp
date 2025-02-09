#include "BitcoinExchange.hpp"

int main(int Argc, char **Argv)
{
	std::string line;
	if (Argc != 2)
		std::cerr << "usage: ./btc <input_file.txt>\n"; return 1;

	std::ifstream inputStream(Argv[1]);
	if (!inputStream.is_open())
		std::cerr << "can't access " << Argv[1] << '\n' ; return 1;
	BitcoinExchange btcExchangeSystem("data.csv");
	btcExchangeSystem.printData();
	while (!inputStream.eof())
	{
		std::getline(inputStream, line);
		try {
			btcExchangeSystem.printAmountPrice(line);
		}
		catch(std::exception &error) {
			std::cerr << "Error: " << error.what() << '\n';
		}
	}
}
