/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <hguo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:37:16 by hguo              #+#    #+#             */
/*   Updated: 2026/02/11 16:37:17 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;
	Bureaucrat boss("Boss", 1);

	AForm* f1 = someRandomIntern.makeForm("robotomy request", "Bender");
	if (f1)
	{
		boss.signForm(*f1);
		boss.executeForm(*f1);
		delete (f1);
	}

	AForm* f2 = someRandomIntern.makeForm("shrubbery creation", "home");
	if (f2)
	{
		boss.signForm(*f2);
		boss.executeForm(*f2);
		delete (f2);
	}

	AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Ford");
	if (f3)
	{
		boss.signForm(*f3);
		boss.executeForm(*f3);
		delete (f3);
	}

	AForm* bad = someRandomIntern.makeForm("coffee making", "me");
	if (bad)
		delete (bad);

	return (0);
}