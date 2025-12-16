#ifndef MATERIASOURCE
#define MATERIASOURCE

#include "IMateriaSource.hpp"
#include <memory>

class AMateria;
class MateriaSource : public IMateriaSource
{
    private:
        AMateria *slots[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        MateriaSource &operator=(const MateriaSource &other);
        ~MateriaSource();

        void learnMateria(AMateria* materia);
        AMateria* createMateria(std::string const & type);
};

#endif