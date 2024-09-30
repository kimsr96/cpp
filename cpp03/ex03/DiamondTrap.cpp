#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("default"), ScavTrap("default"), FragTrap("default"), _name("default"){
    energyPoints = 50;
    std::cout << "Constructor DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) 
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name){
    energyPoints = 50;
    std::cout << "Constructor DiamondTrap called" << std::endl;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "Destructor DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy){
    std::cout << "Copy constructor DiamondTrap called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy){
    if (this != &copy){
        ClapTrap::operator=(copy);
        ScavTrap::operator=(copy);
        FragTrap::operator=(copy);
        _name = copy._name;
        hitPoints = copy.hitPoints;
        energyPoints = copy.energyPoints;
        attackDamage = copy.attackDamage;
    }
    return *this;
}

void    DiamondTrap::attack(const std::string &target){
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI(){
    std::cout << this->_name << "ScavTrap name is " << ScavTrap::_name << 
    " ,FragTrap name is " << FragTrap::_name << 
    " and ClapTrap name is " << ClapTrap::_name << std::endl;
}

void    DiamondTrap::printHitPoint(){
    std::cout << "Hit points : "<< hitPoints << std::endl;
}