/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:19:34 by seungryk          #+#    #+#             */
/*   Updated: 2024/07/02 13:33:35 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
    private:
        std::string _name;
        Weapon     &_weapon;
    public:
        HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}
        ~HumanA();
        void    attack(){
            std::cout << _name << " attacks with their " << _weapon.getType() << std::endl; 
        }
};

#endif