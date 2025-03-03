#pragma once

#include <string>

class Replacer {
	private:
		static bool	open_files(std::string &path, std::ifstream &input_file, std::ofstream &output_file);

	public:
		static int	replace(std::string path, std::string occurrence, std::string replacement);
};
