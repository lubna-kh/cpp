#include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
    
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        j->makeSound(); //will output the Dog sound!
        i->makeSound(); //will output the Cat sound!
        meta->makeSound();
    
        delete meta;
        delete j;
        delete i;
    }
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();
    
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the Cat sound!
        meta->makeSound();
    
        delete meta;
        delete i;
    }
    return 0;
}
