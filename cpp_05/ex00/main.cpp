#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat  b1("Mickael", 5);
    Bureaucrat  b2("Popopolo", 149);


    std::cout << std::endl << "Incrementation tests !!" << std::endl;
    try
    {
        while (true)
        {
            std::cout << b1 << std::endl;
            b1.incrementGrade();
        }
    }
    catch (std::exception& exception)
    {
        std::cout << "Unable to increment grade: " << exception.what() << std::endl;
    }


    std::cout << std::endl << "Decrementation tests !!" << std::endl;
    try
    {
        while (true)
        {
            std::cout << b2 << std::endl;
            b2.decrementGrade();
        }
    }
    catch (std::exception& exception)
    {
        std::cout << "Unable to increment grade: " << exception.what() << std::endl;
    }
    std::cout << std::endl;

	return 0;
}
