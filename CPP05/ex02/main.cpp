/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <hguo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:36:29 by hguo              #+#    #+#             */
/*   Updated: 2026/02/11 16:36:30 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Not signed execute ===" << std::endl;
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm f("home");
		boss.executeForm(f); // should fail: not signed
	}

	std::cout << "\n=== Sign ok, exec ok ===" << std::endl;
	{
		Bureaucrat alice("Alice", 1);
		ShrubberyCreationForm f("garden");
		alice.signForm(f);
		alice.executeForm(f); // should create garden_shrubbery
	}

	std::cout << "\n=== Sign fail (grade too low) ===" << std::endl;
	{
		Bureaucrat low("Low", 150);
		RobotomyRequestForm r("marvin");
		low.signForm(r); // should fail
	}

	std::cout << "\n=== Exec fail (grade too low for execute) ===" << std::endl;
	{
		Bureaucrat signer("Signer", 1);
		Bureaucrat executorLow("ExecutorLow", 150);
		PresidentialPardonForm p("Ford");

		signer.signForm(p);
		executorLow.executeForm(p);
	}

	std::cout << "\n=== Robotomy multiple runs ===" << std::endl;
	{
		Bureaucrat exec("Exec", 1);
		RobotomyRequestForm r("Bender");
		exec.signForm(r);
		for (int i = 0; i < 6; ++i)
			exec.executeForm(r);
	}

	return (0);
}