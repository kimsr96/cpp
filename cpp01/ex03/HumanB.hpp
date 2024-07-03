/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:19:34 by seungryk          #+#    #+#             */
/*   Updated: 2024/07/02 13:40:57 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
    private:
        std::string _name;
        Weapon      *_weapon;
    public:
        HumanB(std::string name) : _name(name), _weapon(NULL) {}
        HumanB();
        ~HumanB();
        void    attack(){
            std::cout << _name << " attacks with their " << _weapon->getType() << std::endl; 
        }
        void    setWeapon(Weapon &weapon){
            _weapon = &weapon;                
        }
};

#endif