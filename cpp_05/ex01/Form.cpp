#include "Form.hpp"

Form::Form(const std::string& name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	if (signGrade < 1 || execGrade < 1)
		throw std::invalid_argument("Grade too high");
	if (signGrade > 150 || execGrade > 150)
		throw std::invalid_argument("Grade too low");
}

Form::~Form()
{

}

Form::Form(const Form &cpy) : _name(cpy._name), _signGrade(cpy._signGrade), _execGrade(cpy._execGrade), _isSigned(cpy._isSigned)
{
	*this = cpy;
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		(const_cast<std::string &>(this->_name) = rhs.getName());
		(const_cast<int &>(this->_signGrade) = rhs.getSignGrade());
		(const_cast<int &>(this->_execGrade) = rhs.getExecGrade());
		this->_isSigned = rhs.getIsSigned();
	}
	return *this;
}

const std::string& Form::getName() const
{
	return this->_name;
}

int Form::getSignGrade() const
{
	return this->_signGrade;
}

int Form::getExecGrade() const
{
	return this->_execGrade;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form: " << form.getName() << " is ";
	if (form.getIsSigned())
		os << "signed" << std::endl;
	else
		os << "not signed" << std::endl;
	os << "Grade to sign the form: " << form.getSignGrade() << std::endl;
	return os;
}