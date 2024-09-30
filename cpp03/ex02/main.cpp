/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:42:46 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/28 15:31:18 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    FragTrap a("a");
    FragTrap b("b");

    for (int i = 0; i < 100; i++)
    {
        a.attack("b");
        b.takeDamage(30);
    }
    a.attack("b");
    a.highFivesGuys();
    return 0;
}
