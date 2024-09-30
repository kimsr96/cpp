#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default"){
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "Constructor FragTrap called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "Constructor FragTrap called" << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "Destructor FragTrap called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy){
    std::cout << "Copy constructor FragTrap called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy){
    if (this != &copy){
        ClapTrap::operator=(copy);
    }
    return *this;
}

void FragTrap::highFivesGuys(){
    std::cout << _name << " positive highFive !" << std::endl; 
}

void FragTrap::attack(const std::string &target){
    if (hitPoints <= 0 || energyPoints <= 0)
    {
        std::cout << _name << " can't do anything !" << std::endl;   
        return ;
    }
    energyPoints -= 1;
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing " \
        << attackDamage << " points of damage!" << std::endl;
    std::cout << _name << " left " << energyPoints << " energy points" << std::endl;
}
