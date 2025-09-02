#include "AForm.hpp"

AForm::AForm(const std::string& name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	if (signGrade < 1 || execGrade < 1)
		throw std::invalid_argument("Grade too high");
	if (signGrade > 150 || execGrade > 150)
		throw std::invalid_argument("Grade too low");
}

AForm::~AForm()
{

}

AForm::AForm(const AForm &cpy) : _name(cpy._name), _signGrade(cpy._signGrade), _execGrade(cpy._execGrade), _isSigned(cpy._isSigned)
{
	*this = cpy;
}

AForm &AForm::operator=(const AForm &rhs)
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

const std::string& AForm::getName() const
{
	return this->_name;
}

int AForm::getSignGrade() const
{
	return this->_signGrade;
}

int AForm::getExecGrade() const
{
	return this->_execGrade;
}

bool AForm::getIsSigned() const
{
	return this->_isSigned;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

const char* AForm::CannotExecuteException::what() const throw()
{
	return "Cannot execute form";
}

std::ostream& operator<<(std::ostream& os, const AForm& Aform)
{
	os << "AForm: " << Aform.getName() << " is ";
	if (Aform.getIsSigned())
		os << "signed" << std::endl;
	else
		os << "not signed" << std::endl;
	os << "Grade to sign the Aform: " << Aform.getSignGrade() << std::endl;
	return os;
}
