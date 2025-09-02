#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &cpy);
	~Intern();

	Intern &operator=(const Intern &rhs);

	AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif
