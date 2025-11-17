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

	Harl	harl;
	switch (index) {
		case 0:
			harl.complain("DEBUG");
			std::cout << std::endl;
		case 1:
			harl.complain("INFO");
			std::cout << std::endl;
		case 2:  
			harl.complain("WARNING");
			std::cout << std::endl;
		case 3:
			harl.complain("ERROR");
			std::cout << std::endl;
			break ;
		default:  
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}

	return (0);
}
