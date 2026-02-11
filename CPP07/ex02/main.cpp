/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <hguo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:31:22 by hguo              #+#    #+#             */
/*   Updated: 2026/02/11 16:31:23 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int	main() {
	// test 1
	Array<int> empty;
	std::cout << "Empty size: " << empty.size() << std::endl;
	std::cout << std::endl;

	//test 2
	Array<int> numbers(5);
	std::cout << "Numbers size: " << numbers.size() << std::endl;
	for (unsigned int i = 0; i < numbers.size(); i++) {
		numbers[i] = i * 10;
		std::cout << "numbers[ " << i << " ] = " << numbers[i] << std::endl; 
	}
	std::cout << std::endl;

	//test 3
	Array<int> a(5);
	a[0] = 42;
	Array<int> b = a;
	b[0] = 126;
	std::cout << "a[0]: " << a[0] << std::endl;
	std::cout << "b[0]: " << b[0] << std::endl;
	std::cout << std::endl;

	//test 4
	try {
		a[10] = 0;
	}
	catch (std::exception &e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	//test 5
	Array<std::string> s(2);
	s[0] = "42 is a Cat programming school";
	s[1] = "I'm in Paris!";
	std::cout << "String: " << s[0] << " | Size: " << s.size() << std::endl;
	std::cout << "String: " << s[1] << " | Size: " << s.size() << std::endl;
	std::cout << std::endl;

	return 0;
}