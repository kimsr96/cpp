/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:19:34 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/11 16:43:05 by seungryk         ###   ########.fr       */
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
        HumanB(std::string name);
        HumanB();
        ~HumanB();
        void    attack();
        void    setWeapon(Weapon &weapon);
};

#endif