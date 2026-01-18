#include "Form.hpp"
#include "Bureaucrat.hpp"

void	Form::checkGrade(int grade)
{
	if (grade < 1)
		throw (Form::GradeTooHighException());
	else if (grade > 150)
		throw (Form::GradeTooLowException());
}

Form::Form() : _name("DefaultForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	Form::checkGrade(_gradeToSign);
	Form::checkGrade(_gradeToExecute);
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

Form::~Form() {}

const std::string& Form::getName() const
{
	return (_name);
}

bool	Form::isSigned() const
{
	return (_isSigned);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw (Form::GradeTooLowException());
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low");
}

std::ostream&	operator<<(std::ostream& os, const Form& f)
{
	os << "Form \"" << f.getName() << "\" "
		<< "[signed=]" << (f.isSigned() ? "true" : "false") << "] "
		<< "gradeToSign=" << f.getGradeToSign() << " "
		<< "gradeToExecute=" << f.getGradeToExecute();
	return (os);
}