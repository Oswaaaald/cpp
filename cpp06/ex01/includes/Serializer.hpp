#ifndef SERIQALIZER_HPP
# define SERIQALIZER_HPP

# include <iostream>
# include <stdint.h>

struct Data
{
	std::string name;
	int			age;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &copy);
		~Serializer();
		Serializer &operator=(const Serializer &copy);
	public:
		static  uintptr_t serialize(Data *ptr);
		static  Data *deserialize(uintptr_t raw);
};

#endif
