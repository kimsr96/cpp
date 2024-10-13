#include "AMateria.hpp"

AMateria::AMateria() : _type("default"){
}

AMateria::AMateria(std::string const & type) : _type(type){
}

AMateria::~AMateria(){
}

AMateria::AMateria(const AMateria &copy) : _type(copy._type){
}

AMateria& AMateria::operator=(const AMateria& copy){
    if (this != &copy)
        _type = copy.getType();
    return *this;
}

const std::string& AMateria::getType() const{
    return (_type);
}

void    AMateria::use(ICharacter& target){
    std::cout << target.getName() << "empty used" << std::endl;
}