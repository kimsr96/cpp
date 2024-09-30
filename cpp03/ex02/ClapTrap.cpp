/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:37:55 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/30 16:49:48 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), hitPoints(10), energyPoints(10), attackDamage(0){
    std::cout << "Constructor ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "Constructor ClapTrap called" << std::endl;
}

ClapTrap::~ClapTrap() { 
    std::cout << "Destructor ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
: _name(copy._name), hitPoints(copy.hitPoints), energyPoints(copy.energyPoints), attackDamage(copy.attackDamage){
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy){
    if (this != &copy)
    {
        _name = copy._name;
        hitPoints = copy.hitPoints;
        energyPoints = copy.energyPoints;
        attackDamage = copy.attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string &target){
    if (this->hitPoints <= 0 || this->energyPoints <= 0)
    {
        std::cout << this->_name << " can't do anything !" << std::endl;   
        return ;
    }
    this->energyPoints -= 1;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " \
        << attackDamage << " points of damage!" << std::endl;
    std::cout << _name << " left " << energyPoints << "energy points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->hitPoints <= 0 || this->energyPoints <= 0)
    {
        std::cout << this->_name << " can't do anything !" << std::endl;   
        return ;
    }
    this->hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount << " damages" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->hitPoints <= 0 || this->energyPoints <= 0)
    {
        std::cout << this->_name << " can't do anything !" << std::endl;   
        return ;
    }
    this->energyPoints -= 1;
    this->hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repaired " << amount << " points" << std::endl;
}
