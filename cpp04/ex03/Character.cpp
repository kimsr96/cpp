#include "Character.hpp"
#include "List.hpp"

Character::Character(){
    for (int i = 0; i < 4; i++)
        _mList[i] = NULL;
}

Character::Character(std::string name) : _idx(0), _name(name){
    for (int i = 0; i < 4; i++)
        _mList[i] = NULL;
}

Character::~Character(){
    for (int i = 0; i < 4; i++)
    {
        if (this->_mList[i])
            delete _mList[i];
    }
}

Character::Character(const Character &copy) : _idx(copy._idx),  _name(copy._name){
}

Character& Character::operator=(const Character& copy){
    if (this != &copy){
        _name = copy._name;
        _idx = copy._idx;
    }
    return *this;
}

std::string const & Character::getName() const{
    return _name;
}

void    Character::equip(AMateria* m){
    if (m == NULL)
        return ;
    if (_idx >= 4)
    {
        std::cout << "4 slots are full" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (_mList[i] == NULL)
        {
            _mList[i] = m;
            _idx++;
            return ;
        }
    }
}

void    Character::unequip(int idx){
    if (idx < 0 || idx >= 4)
    {
        std::cout << "index is not valid" << std::endl;
        return ;
    }
    if (_mList[idx])
    {
        add_node(_mList[idx]);
        _mList[idx] = NULL;
        _idx--;
    }
    else
        std::cout << "Already unequiped" << std::endl;
}

void    Character::use(int idx, ICharacter& target){
    if (idx < 0 || idx >= 4)
    {
        std::cout << idx << "not suitable" << std::endl;
        return ;
    }
    if (_mList[idx])
        _mList[idx]->use(target);
    else
        std::cout << "No AMateria in slots" << std::endl;
}