#include "Serializer.hpp"

int main()
{
	Data data;


	data.value = "Hello World";



	uintptr_t raw = Serializer::serialize(&data);

	std::cout << raw << std::endl;

	Data new_data = *Serializer::deserialize(raw);

	std::cout << new_data.value << std::endl;
	std::cout << data.value << std::endl;

	return 0;
}
