#ifndef HUMANB_HPP
#define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB{
    private:
        std::string name;
        // i used pointer to allow the weapon to be null
        Weapon *weapon;

    public:
        void    attack() const;
        void    setWeapon(Weapon &weapon);
        HumanB(std::string name);
};

#endif