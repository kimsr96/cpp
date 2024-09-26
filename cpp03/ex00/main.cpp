/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:42:46 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/25 15:58:28 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("a");
    ClapTrap b("b");

    a.attack("b");
    for (int i = 0; i < 11; i++)
        b.takeDamage(1);
    a.beRepaired(1);
    b.beRepaired(1);
    
    return 0;
}
