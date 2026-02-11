/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <hguo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:35:48 by hguo              #+#    #+#             */
/*   Updated: 2026/02/11 16:35:49 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Form;

class Bureaucrat
{
	private:  
		const std::string	_name;
		int					_grade;

	public:  
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		// getters
		const std::string&	getName() const;
		int					getGrade() const;

		// grade operations
		void	incrementGrade();
		void	decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:  
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:  
				virtual const char* what() const throw();
		};

		void	signForm(Form& f);
	
	private:  
		static void	checkGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif