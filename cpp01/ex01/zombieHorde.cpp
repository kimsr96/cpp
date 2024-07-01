/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:56:53 by seungryk          #+#    #+#             */
/*   Updated: 2024/07/01 16:29:39 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *zombiHorde( int N, std::string name)
{
    int     i;
    Zombie  *z_horde = new Zombie[N];
    
    for (i = 0; i < N; i++)
    {
        z_horde[i].set_name(name + std::to_string(i));
        z_horde[i].announce();
    }
    return (z_horde);
}