#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _idx(0){
    for (int i = 0; i < 4; i++)
        slots[i] = NULL;
}

MateriaSource::~MateriaSource(){
    for (int i = 0; i < 4; i++)
    {
        if (this->slots[i])
            delete slots[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource &copy) : _idx(copy._idx){
        for (int i = 0; i < 4; i++)
        {
            if (copy.slots[i])
                this->slots[i] = copy.slots[i]->clone();
            else
                this->slots[i] = NULL;
        }
} 

MateriaSource& MateriaSource::operator=(const MateriaSource& copy){
    if (this != &copy)
    {
        this->_idx = copy._idx;
        for (int i = 0; i < 4; i++)
        {
            if (this->slots[i])
                delete this->slots[i];
            if (copy.slots[i])
                this->slots[i] = copy.slots[i]->clone();
            else
                this->slots[i] = NULL;
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *skill){
    if (skill == NULL)
        return ;
    if (_idx >= 4)
    {
        std::cout << "4 slots are full" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (slots[i] == NULL)
        {
            slots[i] = skill;
            _idx++;
            return ;
        }
    }
}

AMateria*   MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; i++)
    {
        if (type == slots[i]->getType() && type == "ice")
            return (new Ice());
        else if (type == slots[i]->getType() && type == "cure")
            return (new Cure());
    }
    return (0);
}