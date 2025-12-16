#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout<<"MateriaSource Default Constructor\n";
    for (int i=0;i < 4;i++)
        slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    std::cout<<"MateriaSource Copy Constructor\n";
    for (int i=0;i < 4;i++)
    {
        if (other.slots[i])
            slots[i] = other.slots[i]->clone();
        else
            slots[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    std::cout<<"MateriaSource Copy Assignmet Constructor\n";
    if (this != &other)
    {
        for (int i=0;i < 4;i++)
        {
            if (slots[i])
            {
                delete slots[i];
                slots[i] = NULL;
            }
            if (other.slots[i])
                slots[i] = other.slots[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
    for (int i=0;i < 4;i++)
    {
        if (slots[i] == NULL)
        {
            slots[i] = materia;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0;i < 4;i++)
    {
        if (slots[i] != NULL)
        {
            if (slots[i]->getType() == type)
                return(slots[i]->clone());
        }
    }
    return 0;
}

MateriaSource::~MateriaSource()
{
    std::cout<<"MateriaSource Default destructor\n";
    for (int i = 0;i < 4;i++)
    {
        if (slots[i] != NULL)
            delete slots[i];
    }
}