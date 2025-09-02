#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &cpy)
{
	*this = cpy;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string list[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	AForm* final = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (formName == list[i])
		{
			final = forms[i];
			std::cout << "Intern creates " << formName << std::endl;
		}
		else
			delete forms[i];
	}

	if (!final)
		std::cout << "Intern cannot create " << formName << " because it does not exist" << std::endl;

	return final;
}
