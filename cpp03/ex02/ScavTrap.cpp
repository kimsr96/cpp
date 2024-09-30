#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default"){
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "Constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "Constructor ScavTrap called" << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "Destructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy){
    std::cout << "Copy constructor ScavTrap called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy){
    if (this != &copy){
        ClapTrap::operator=(copy);
    }
    return *this;
}

void ScavTrap::guardGate(){
    std::cout << _name << " ScavTrap is now in Gate Keeper Mode" << std::endl; 
}

void ScavTrap::attack(const std::string &target){
    if (hitPoints <= 0 || energyPoints <= 0)
    {
        std::cout << _name << " can't do anything !" << std::endl;   
        return ;
    }
    energyPoints -= 1;
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " \
        << attackDamage << " points of damage!" << std::endl;
    std::cout << _name << " left " << energyPoints << " energy points" << std::endl;
}
