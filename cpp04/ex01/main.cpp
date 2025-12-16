#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal *animals[4];
	
	for (int i = 0;i < 4;i++)
	{
		for (;i < 2;i++)
		{
			animals[i] = new Cat();	
		}
		animals[i] = new Dog();
	}
	Dog *d1 = new Dog();
	Dog *d2 = new Dog();
	*d1 = *d2;
	for (int i=0;i < 4;i++)
	{
		delete animals[i];
	}
	delete d1;
	delete d2;
	// Dog basic;
	// {
	// 	Dog tmp = basic;
	// }
	// std::cout<<"hi\n";


	
	// Animal *ani = new Dog();
	// delete ani;
	return 0;
}
