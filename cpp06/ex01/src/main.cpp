#include "../includes/Serializer.hpp"

int main() {
	Data originalData = {"Jakaub", 25};

	// Original data
	std::cout << "Original Data Address: " << &originalData << std::endl;
	std::cout << "Name: " << originalData.name << std::endl;
	std::cout << "Age: " << originalData.age << std::endl;

	// Serialize the data (convert the pointer to a raw data)
	uintptr_t raw = Serializer::serialize(&originalData);
	std::cout << "Serialized Data: " << raw << std::endl;

	// Build the raw data back to a pointer
	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized Data Address: " << deserializedData << std::endl;
	std::cout << "Name: " << deserializedData->name << std::endl;
	std::cout << "Age: " << deserializedData->age << std::endl;

	if (deserializedData == &originalData)
		std::cout << "Success: That's the same bro!" << std::endl;
	else
		std::cout << "Error: Not the same bro!" << std::endl;
	return 0;
}
