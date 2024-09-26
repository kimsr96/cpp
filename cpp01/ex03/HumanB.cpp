/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:14:04 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/11 18:28:48 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){
}

HumanB::~HumanB(){
}

void HumanB::attack(){
    if (_weapon == NULL)
        std::cout << _name << " has no weapon" << std::endl;
    else
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl; 
}

void HumanB::setWeapon(Weapon &weapon){
    _weapon = &weapon;                
}