#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria *slots[4];
        AMateria *addr[500];
        int unequipCount;
    public://here copy constructor and Assignment must do deep copy(clone Materias instead of just copying pointers)
        Character();
        Character(std::string name);
        Character(const Character &other);
        Character &operator=(const Character &other);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif