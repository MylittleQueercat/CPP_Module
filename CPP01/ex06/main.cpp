#include "Harl.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
		return (1);
	}

	std::string level = argv[1];
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	index = -1;
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			index = i;
			break ;
		}
	}

	Harl	Harl;
	switch (index) {
		case 0:
			Harl.complain("DEBUG");
			std::cout << std::endl;
		case 1:
			Harl.complain("INFO");
			std::cout << std::endl;
		case 2:  
			Harl.complain("WARNING");
			std::cout << std::endl;
		case 3:
			Harl.complain("ERROR");
			std::cout << std::endl;
		default:  
			return (0);
	}

	return (0);
}
