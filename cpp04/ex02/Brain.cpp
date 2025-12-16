#include "Brain.hpp"

Brain::Brain()
{
    std::cout<< "Brain Default Constructor"<<std::endl;
    for (int i=0;i < 100;i++)
    {
        ideas[i] = "default";
    }
}

Brain::~Brain()
{
    std::cout<< "Brain Destructor Called"<<std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout<< "Brain Copy Constructor"<<std::endl;
    for (int i = 0;i < 100;i++)
        this->ideas[i] = other.ideas[i];
    // for (int i = 0;i < 100;i++)
    //     std::cout<< other.ideas[i]<<"\n";
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout<< "Brain Copy Assignment Constructor"<<std::endl;
    if (this != &other)
    {
        for (int i = 0;i < 100;i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}
