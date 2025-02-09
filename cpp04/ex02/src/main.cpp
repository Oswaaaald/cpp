#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	const int nbAnimals = 100;
	const Animal* animals[nbAnimals];
	for (int i = 0; i < nbAnimals; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < nbAnimals; i++)
		std::cout << animals[i]->getType() << std::endl;

	for (int i = 0; i < nbAnimals; i++)
		delete animals[i];

	std::cout << "\033[36mDeep copy :\033[0m" << std::endl;
	
	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "I am the OG dog");
	Dog copyDog = originalDog;
	copyDog.getBrain()->setIdea(0, "I am the copy dog");
	Cat originalCat;
	originalCat.getBrain()->setIdea(0, "I am the OG cat");
	Cat copyCat(originalCat);
	copyCat.getBrain()->setIdea(0, "I am the copy cat");
	WrongCat originalWrongCat;
	originalWrongCat.getBrain()->setIdea(0, "I am the OG wrong cat");
	WrongCat copyWrongCat(originalWrongCat);
	copyWrongCat.getBrain()->setIdea(0, "I am the copy wrong cat");

	std::cout << "Original dog idea[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy dog idea[0]: " << copyDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Original cat idea[0]: " << originalCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy cat idea[0]: " << copyCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "Original wrong cat idea[0]: " << originalWrongCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy wrong cat idea[0]: " << copyWrongCat.getBrain()->getIdea(0) << std::endl;

	// Usefull to compare with ex01
	//const Animal* animal = new Animal();
	//std::cout << "Hi, I am a " << animal->getType() << " and I don't have a Brain!" << std::endl;
	//animal->makeSound();
	//delete animal;

	//check 100 ideas
	//Dog ideaDog;
	//for (int i = 0; i < 100; i++)
	//{
	//	ideaDog.getBrain()->setIdea(i, "Idea ");
	//}
	//int k = 0;
	//while (ideaDog.getBrain()->getIdea(k) != "Invalid index")
	//{
	//	std::cout << k << std::endl;
	//	k++;
	//}

	return 0;
}