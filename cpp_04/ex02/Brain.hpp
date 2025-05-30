#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &other);
		virtual ~Brain();
		
		Brain &operator=(const Brain &other);

		std::string getIdea(int index) const;
		void setIdea(int index, const std::string &idea);
};

#endif