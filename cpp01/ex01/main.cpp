/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:53:58 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/11 15:02:14 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//void    check_leaks(void)
//{
//    system("leaks zombie_horde");
//}

int main(void)
{
    int     N = 5;
    Zombie  *zombieArray = zombiHorde(N, "zombie");
    if (zombieArray == NULL)
        return (1);
    delete[] zombieArray;
    //atexit(check_leaks);
    return (0);
}