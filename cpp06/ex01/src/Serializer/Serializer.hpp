#pragma once

#include "Data/Data.hpp"
#include <stdint.h>

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &sl);

		Serializer	&operator=(const Serializer &sl);

		~Serializer();

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};
