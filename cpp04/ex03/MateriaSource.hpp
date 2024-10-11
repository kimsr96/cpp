#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource{
    private:
        int      _idx;
        AMateria *slots[4];
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource &copy);
        MateriaSource &operator=(const MateriaSource &copy);
        
        void        learnMateria(AMateria* skill);
        AMateria    *createMateria(std::string const & type);
};

#endif