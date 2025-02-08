#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{

	std::cout << "\033[36mInit :\033[0m" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << "\033[36mGet Types :\033[0m" << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << wrongAnimal->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;

	std::cout << "\033[36mMake sounds :\033[0m" << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound(); //will output the animal sound!
	wrongAnimal->makeSound(); //will output the wrongAnimal sound!
	wrongCat->makeSound(); //will output the wrongCat sound!

	std::cout << "\033[36mCall destructors :\033[0m" << std::endl;

	delete meta;
	delete i;
	delete j;
	delete wrongAnimal;
	delete wrongCat;
	
	return 0;
}