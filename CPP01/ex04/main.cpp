#include <iostream>
#include <string>
#include <fstream>

std::string	replaceAll(const std::string &line, const std::string &s1, const std::string &s2) {
	std::string	result;
	size_t	pos = 0;
	size_t	found;

	while ((found = line.find(s1, pos)) != std::string::npos) {
		result.append(line, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(line, pos, line.length() - pos);
	return (result);
}

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) {
		std::cout << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}

	std::ifstream input(filename.c_str());
	if (!input) {
		std::cerr << "Error: cannot open input file" << std::endl;
		return (1);
	}

	std::ofstream output((filename + ".replace").c_str());
	if (!output) {
		std::cerr << "Error: cannot create output file" << std::endl;
		return (1);
	}

	std::string line;
	while (std::getline(input, line)) {
		std::string replaced = replaceAll(line, s1, s2);
		output << replaced << std::endl;
	}

	return (0);
}