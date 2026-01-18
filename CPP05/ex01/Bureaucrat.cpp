#include "Bureaucrat.hpp"
#include "Form.hpp"

void	Bureaucrat::checkGrade (int grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	Bureaucrat::checkGrade(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	Bureaucrat::checkGrade(_grade - 1);
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	Bureaucrat::checkGrade(_grade + 1);
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

void	Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << f.getName()
				<< " because " << e.what() << "." << std::endl;
	}
	
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}