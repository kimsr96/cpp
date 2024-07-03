/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:11:33 by seungryk          #+#    #+#             */
/*   Updated: 2024/07/02 12:40:57 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>

class Weapon{
    private:
        std::string _type;
    public:
        Weapon(std::string type){
            _type = type; 
        }
        Weapon();
        ~Weapon();
        const std::string& getType() const{
            return (_type);
        }
        void setType(std::string type){
            _type = type;            
        }   
};

#endif