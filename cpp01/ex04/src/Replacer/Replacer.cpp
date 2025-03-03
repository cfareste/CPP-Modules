#include "Replacer.hpp"
#include <fstream>
#include <iostream>

int Replacer::replace(std::string path, std::string occurrence, std::string replacement)
{
	std::ifstream	input_file;
	std::ofstream	output_file;
	std::string		line;

	input_file.open(path, std::ios::in);
	if (!input_file.is_open())
	{
		std::cout << "Error while opening '" << path << "' file" << std::endl;
		return 1;
	}
	output_file.open(path + ".replace", std::ios::trunc);
	if (!output_file.is_open())
	{
		std::cout << "Error while opening output file" << std::endl;
		input_file.close();
		return 1;
	}

	while (std::getline(input_file, line))
	{
		size_t	occurrence_pos = line.find(occurrence, 0);

		while (occurrence_pos != std::string::npos)
		{
			line.erase(occurrence_pos, occurrence.size());
			line.insert(occurrence_pos, replacement);
			occurrence_pos = line.find(occurrence, occurrence_pos + 1);
		}

		output_file << line << std::endl;
	}
	output_file.close();
	input_file.close();

	return 0;
}
