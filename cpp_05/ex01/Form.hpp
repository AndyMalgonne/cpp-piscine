#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
    Form(const std::string& name, int signGrade, int execGrade);
	Form(const Form &cpy);
    ~Form();

	Form &operator=(const Form &rhs);

    const std::string& getName() const;
	bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
    const std::string _name;
    const int _signGrade;
    const int _execGrade;
    bool _isSigned;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif