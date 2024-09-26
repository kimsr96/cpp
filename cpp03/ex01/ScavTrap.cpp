#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): _name("default"), hitPoints(100), energyPoints(50), attackDamage(20){
    std::cout << "Constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): _name(name), hitPoints(100), energyPoints(50), attackDamage(20){
    std::cout << "Constructor ScavTrap called" << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "Destructor ScavTrap called" << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << this->_name << " ScavTrap is now in Gate Keeper Mode" << std::endl; 
}

