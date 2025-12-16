#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria &other);
        AMateria &operator=(const AMateria &other);
        virtual ~AMateria();

        std::string const & getType() const;
        virtual AMateria* clone() const = 0;//return new ice/new cure as a copy from it self
        virtual void use(ICharacter& target);//can be overriden 
};

#endif