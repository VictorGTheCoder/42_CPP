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
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private:
		Serializer();
		Serializer(Serializer &serializer);
		~Serializer();

		Serializer &operator=(const Serializer &src);
};

#endif
