/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <hguo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:36:40 by hguo              #+#    #+#             */
/*   Updated: 2026/02/11 16:36:41 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open()) {
		std::cout << "Error: Could not create shrubbery file." << std::endl;
		return;
	}

	file
	<< "====================== SHRUBBERY GROVE ======================\n"
	<< "\n"
	<< "      @@@@          ****           ^^^^^            &&&&\n"
	<< "     @@@@@@        ******         ^^^^^^^          &&&&&&\n"
	<< "    @@@@@@@@@     ********       ^^^^^^^^^        &&&&&&&&\n"
	<< "     @@@@@@        ******         ^^^^^^^          &&&&&&\n"
	<< "      @@@@          ****           ^^^^^            &&&&\n"
	<< "       ||             |              |               |||\n"
	<< "       ||             |              |               |||\n"
	<< "     --------       --------       --------        --------\n"
	<< "\n"
	<< "      ####          0000          ++++            $$$$\n"
	<< "     ######        000000        ++++++          $$$$$$\n"
	<< "   ##########     00000000     ++++++++++       $$$$$$$$\n"
	<< "     ######        000000        ++++++          $$$$$$\n"
	<< "      ####          0000          ++++            $$$$\n"
	<< "       ||             |             |              ||\n"
	<< "       ||             |             |              ||\n"
	<< "     --------       --------       --------      --------\n"
	<< "\n"
	<< "                Eight Different Tree Species\n"
	<< "============================================================\n";
}
