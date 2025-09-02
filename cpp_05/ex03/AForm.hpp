#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
    AForm(const std::string& name, int signGrade, int execGrade);
	AForm(const AForm &cpy);
    virtual ~AForm();

	AForm &operator=(const AForm &rhs);

    const std::string& getName() const;
	bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class CannotExecuteException : public std::exception {
	public:
		virtual const char *what() const throw();
	};


private:
    const std::string _name;
    const int _signGrade;
    const int _execGrade;
    bool _isSigned;
};

std::ostream& operator<<(std::ostream& os, const AForm& Aform);

#endif