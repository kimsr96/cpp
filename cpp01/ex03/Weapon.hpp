/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:11:33 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/11 18:56:03 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>

class Weapon{
    private:
        std::string _type;
    public:
        Weapon(std::string type);
        Weapon();
        ~Weapon();
        const std::string& getType() const;
        void setType(std::string type);
};

#endif