#include "Data.hpp"

Data::Data()
{
	this->data = 42;
}

Data::Data(const Data &data)
{
	this->data = data.data;
}

int	Data::getData()
{
	return this->data;
}

Data	&Data::operator=(const Data &data)
{
	if (this == &data) return *this;

	this->data = data.data;
	return *this;
}

Data::~Data()
{
}
