#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

//in abstract class i can create pointers or reference
int main()
{
	// AAnimal animal;//i can not do obj from abstract class
	AAnimal *animals[4];//array of pointers not object

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
	return 0;
}
