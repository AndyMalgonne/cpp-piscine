#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
    std::string s1;
	std::string s2;
	unsigned int n;
};

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const & cpy);
	public:
		~Serializer();

		Serializer & operator=(Serializer const & cpy);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif