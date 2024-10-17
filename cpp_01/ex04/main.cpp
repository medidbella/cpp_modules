#include "include.hpp"

int main(int ac, char **av)
{
	int occur_idx;

	if (ac != 4)
		return 1;

	std::string in_file = av[1];
	std::string out_file = in_file + ".replace";
	std::string line;
	std::ifstream in_stream(in_file.c_str());
	std::ofstream out_stream(out_file.c_str());

	if (!in_stream.is_open())
		std::cerr << "can't open " << av[1] << '\n';
	else if (!out_stream.is_open())
		std::cerr << "can't open the output file \n";
	while (!in_stream.eof())
	{
		std::getline(in_stream, line);
		occur_idx = line.find(av[2]);
		for (int i = 0; i < (int)line.size(); i++)
		{
			if (i == occur_idx)
			{
				out_stream << av[3];
				i += std::strlen(av[2]);
				occur_idx = line.find(av[2], i);
				continue ;
			}
			out_stream << line[i];
		}
		out_stream << '\n';
	}
}