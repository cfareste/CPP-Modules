#include "Serializer/Serializer.hpp"
#include <iostream>

int	main()
{
	Data		data = Data();
	Data		*data_ptr;
	uintptr_t	serialized_data;

	std::cout << "Data value: " << data.getData() << std::endl;
	std::cout << "Data address: " << &data << std::endl;

	serialized_data = Serializer::serialize(&data);

	std::cout << "Serialized data: " << serialized_data << std::endl;

	data_ptr = Serializer::deserialize(serialized_data);

	std::cout << "Deserialized data: " << data_ptr->getData() << std::endl;
	std::cout << "Deserialized data addres: " << data_ptr << std::endl;

	serialized_data = Serializer::serialize(data_ptr);

	std::cout << "New serialized data (deserialized-data serialized): " << serialized_data << std::endl;

	return 0;
}