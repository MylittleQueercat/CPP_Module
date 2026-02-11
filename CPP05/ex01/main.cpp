/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <hguo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:35:58 by hguo              #+#    #+#             */
/*   Updated: 2026/02/11 16:35:59 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	// 1
	{
		Bureaucrat a("Alice", 10);
		Form f("TaxForm", 20, 30);
		std::cout << a << std::endl;
		std::cout << f << std::endl;
		a.signForm(f);
		std::cout << f << std::endl;
	}

	std::cout << "-----------------\n";

	// 2
	{
		Bureaucrat b("Bob", 50);
		Form f("SecretForm", 20, 30);
		b.signForm(f);
	}

	std::cout << "-----------------\n";

	// 3
	try
	{
		Form bad("BadForm", 0, 151);
		std::cout << bad << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Form constructor failed: " << e.what() << std::endl;
	}
	return (0);
}
