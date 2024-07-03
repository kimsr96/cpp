/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:28:42 by seungryk          #+#    #+#             */
/*   Updated: 2024/07/03 14:09:47 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
}

Harl::~Harl(){
}

int    hash( std::string &level)
{
    unsigned long hash = 5381;

    for (size_t i = 0; i < level.length(); i++)
        hash = hash * 33 + level[i];
    return (hash);
}

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl; 
    std::cout << "I really do!" << std::endl; 
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain( std::string level )
{
    int idx;
    
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (idx = 0; idx < 4; idx++)
    {
        if (levels[idx] == level)
            break ;        
    }
    switch (idx)
    {
        case 0:
            debug();
            break ;
        case 1:
            info();
            break ;
        case 2:
            warning();
            break ;
        case 3:
            error();
            break ;
        default :
            break ;
    }
}
