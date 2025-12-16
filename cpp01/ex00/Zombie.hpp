#ifndef ZOMBI_CPP
#define ZOMBI_CPP

#include <iostream>
#include <string>

class Zombie {
    public:
        Zombie(std::string name);
        ~Zombie();
        void    announce( void ) const;

    private:
        std::string name;

};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif