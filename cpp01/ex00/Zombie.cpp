/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:43:53 by seungryk          #+#    #+#             */
/*   Updated: 2024/07/01 15:54:09 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
    std::cout << "Zombie created!" << std::endl;
}

Zombie::~Zombie(){
    std::cout << "Zombie " << _name << " deleted" << std::endl;
}

void    Zombie::announce( void ){
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::set_name(std::string name){
    _name = name;
}

Zombie  *newZombie( std::string name )
{
    Zombie *Zb;
    
    Zb = new Zombie();
    Zb->set_name(name); 
    return (Zb);
}