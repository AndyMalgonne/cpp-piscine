#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy)
{
	*this = cpy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw AForm::CannotExecuteException();

	std::ofstream out((executor.getName() + "_shrubbery").c_str());
	if (!out.is_open())
		throw AForm::CannotExecuteException();

	std::cout << executor.getName() << " executed " << this->getName() << std::endl;

	out << "           `-._\\/  .  \\ /    |/_" << std::endl;
	out << "               \\  _\\, y | \\//" << std::endl;
	out << "         _\\_.___\\, \\/ -.\\||" << std::endl;
	out << "           `7-,--.`._||  / / ," << std::endl;
	out << "                `-. `./ / |/_.'" << std::endl;
	out << "                     |    |//" << std::endl;
	out << "                     |_    /" << std::endl;
	out << "                     |-   |" << std::endl;
	out << "                     |   =|" << std::endl;
	out << "                     |    |" << std::endl;
	out << "--------------------/ ,  . \\-------" << std::endl;
}
