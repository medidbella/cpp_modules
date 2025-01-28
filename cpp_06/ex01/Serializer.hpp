#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
// #include <cstdint>

typedef unsigned long uintptr_t;

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private:
		Serializer();
		Serializer(const Serializer &source);
		Serializer &operator=(const Serializer &source);
		~Serializer();
};

#endif
