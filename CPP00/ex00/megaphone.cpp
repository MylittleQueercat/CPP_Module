#include <iostream>
#include <string>
#include <cctype>

std::string	ft_toupper(const char *str)
{
	std::string result(str);
	for (size_t i = 0; i < result.size(); i++)
		result[i] = std::toupper(static_cast<unsigned char>(result[i]));
	return (result);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; av[i]; i++)
			std::cout << ft_toupper(av[i]);
		std::cout << std::endl;
	}
	return (0);
}
