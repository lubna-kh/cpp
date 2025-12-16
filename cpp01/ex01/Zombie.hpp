#ifndef ZOMBI_HPP
#define ZOMBI_HPP

#include <iostream>
#include <string>

class Zombie{
    public:
        Zombie(std::string name);
        Zombie();
        ~Zombie();
        void    announce( void ) const;
    private:
        std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif