/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:21:24 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/11 18:55:38 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type){
    _type = type;
};

Weapon::~Weapon(){
};
        
void Weapon::setType(std::string type){
    _type = type;            
};

const std::string& Weapon::getType() const{
    return (_type);
}