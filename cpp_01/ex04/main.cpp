#include "include.hpp"

int main(int ac, char **av)
{
	int occur_idx;

	if (ac != 4 || !av[2][0]){
		std::cerr << "usage: <file_name> <str1> <str2>\n";
		return 1;
	}
	size_t len = std::strlen(av[2]);
	std::string in_file = av[1];
	std::string out_file = in_file + ".replace";
	std::string line;
	std::ifstream in_stream(av[1]);
	std::ofstream out_stream(out_file.c_str());
	if (!in_stream.is_open())
		std::cerr << "can't open " << av[1] << '\n';
	else if (!out_stream.is_open())
		std::cerr << "can't open the output file \n";
	while (std::getline(in_stream, line))
	{
		while (1)
		{
			occur_idx = line.find(av[2]);
			if (occur_idx == -1)
				break;
			line.erase(occur_idx, len);
			line.insert(occur_idx, av[3]);
		}
		out_stream << line; 
		if (in_stream.fail() && in_stream.eof())
			out_stream << '\n';
	}
}
