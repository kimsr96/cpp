#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"


class Character : public ICharacter{
    private:
        int         _idx;
        std::string _name;
        AMateria*   _mList[4];
    public:
        Character();
        Character(std::string name);
        Character(const Character& copy);
        Character& operator=(const Character& copy);
        ~Character();

        const std::string & getName() const; 
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif