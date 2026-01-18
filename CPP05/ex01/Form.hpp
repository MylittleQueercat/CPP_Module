#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form
{
	private:  
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		//getters
		const	std::string& getName() const;
		bool	isSigned() const;
		int		getGradeToSign() const;
		int		getGradeToExecute() const;

		//action
		void	beSigned(const Bureaucrat& b);

		//exception
		class	GradeTooHighException : public std::exception
		{
			public:  
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:  
				virtual const char* what() const throw();
		};

	private:  
		static void	checkGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif