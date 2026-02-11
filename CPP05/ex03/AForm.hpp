/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <hguo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:36:56 by hguo              #+#    #+#             */
/*   Updated: 2026/02/11 16:36:57 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm
{
	private:  
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		//getters
		const	std::string& getName() const;
		bool	isSigned() const;
		int		getGradeToSign() const;
		int		getGradeToExecute() const;

		//action
		void	beSigned(Bureaucrat const& b);
		void	execute(Bureaucrat const& executor) const;

		//exception
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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	
	protected:  
		virtual void executeAction() const = 0;

	private:  
		static void	checkGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif