# include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout<< "WrongCat Default Constructor"<<std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout<< "WrongCat Copy Constructor"<<std::endl;
    this->type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout<< "WrongCat Copy Assignment Constructor"<<std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout<< "WrongCat Sound" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout<< "WrongCat Destructor Called"<<std::endl;
}