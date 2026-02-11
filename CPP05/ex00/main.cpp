/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <hguo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:36:11 by hguo              #+#    #+#             */
/*   Updated: 2026/02/11 16:36:12 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Eve", 1);
		std::cout << a << std::endl;
		a.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("Alice", 150);
		std::cout << b << std::endl;
		b.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat c("Bear", 17);
		std::cout << c << std::endl;
		c.incrementGrade();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
