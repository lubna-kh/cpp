#include "Character.hpp"


Character::Character()
{
    std::cout<<"Character Default Constructor\n";\
    unequipCount = 0;
    for (int i=0;i < 4;i++)
    {
        slots[i] = NULL;
    }
    for (int i=0;i < 500;i++)
    {
        addr[i] = NULL;
    }
}

Character::Character(std::string name)
{
    std::cout<<"Character Default Constructor\n";
    unequipCount = 0;
    this->name = name;
    for (int i = 0;i < 4;i++)
    {
        slots[i] = NULL;
    }
    for (int i=0;i < 500;i++)
    {
        addr[i] = NULL;
    }
}

Character::Character(const Character &other)
{
    std::cout<<"Character Copy Constructor\n";
    this->name = other.name;
    unequipCount = 0;
    for (int i=0;i < 4;i++)
    {
        if (other.slots[i])
            slots[i] = other.slots[i]->clone();
        else
            slots[i] = NULL;
    }
    for (int i=0;i < 500;i++)
    {
        addr[i] = NULL;
    }
}

Character &Character::operator=(const Character &other)
{
    std::cout<<"Character Copy Assignmet Constructor\n";
    if (this != &other)
    {
        this->name = other.name;
        unequipCount = 0;
        for (int i=0;i < 4;i++)
        {
            if(slots[i])
            {
                delete slots[i];
                slots[i] = NULL;
            }
            if (other.slots[i])
                slots[i] = other.slots[i]->clone();
        }
        for (int i=0;i < 500;i++)
        {
            addr[i] = NULL;
        }
    }
    return *this;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 4 || idx < 0)
        return;
    if (slots[idx] != NULL)
        slots[idx]->use(target);
}

std::string const & Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    for (int i=0;i < 4;i++)
    {
        if (slots[i] == NULL)
        {
            slots[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 4 || idx < 0)
        return;
    if (unequipCount >= 500)
    {
        std::cerr<<"The Floor is full no space to unequip\n";
        return;
    }
    if (slots[idx] != NULL)
    {
        addr[unequipCount] = slots[idx];
        slots[idx] = NULL;
        unequipCount++;
    }
}

Character::~Character()
{
    std::cout<<"Character Default destructor\n";
    for (int i = 0;i < 4;i++)
    {
        if (slots[i])
            delete slots[i];
    }
    for (int i = 0;i < unequipCount;i++)
    {
        if (addr[i])
            delete addr[i];
    }

}