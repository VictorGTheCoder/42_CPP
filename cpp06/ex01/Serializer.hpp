#ifndef SERIALIZE
# define SERIALIZE

#include <iostream>

#include <stdint.h>



typedef struct s_Data
{
	std::string value;
} Data;


class Serializer
{
	public:
		Serializer();
		Serializer(Serializer &serializer);
		~Serializer();


		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

		Serializer &operator=(const Serializer &src);
};

#endif
