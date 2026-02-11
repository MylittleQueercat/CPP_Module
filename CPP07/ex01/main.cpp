/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <hguo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:31:15 by hguo              #+#    #+#             */
/*   Updated: 2026/02/11 16:31:16 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printElement(T const &e) {
	std::cout << e << " ";
}

int main(void) {
	int arr[] = {0, 1, 2, 3, 4};
	std::cout << "Int array: ";
	::iter(arr, 5, printElement<int>);
	std::cout << std::endl;

	std::string strArr[] = {"cat", "rabbit", "dog"};
	std::cout << "String array: ";
	::iter(strArr, 3, printElement<std::string>);
	std::cout << std::endl;

	const int carr[] = {10, 20, 30};
	std::cout << "Const int array: ";
	::iter(carr, 3, printElement<int>);
	std::cout << std::endl;

	return 0;
}