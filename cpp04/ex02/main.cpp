/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:42:46 by seungryk          #+#    #+#             */
/*   Updated: 2024/10/08 17:06:55 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <stdlib.h>

void    check_leaks(void)
{
    system("leaks a.out");
}

int main() 
{
    atexit(check_leaks);
    
    int size = 10;
    Cat *cat[size];
    Dog *dog[size];
    for (int i = 0; i < size; i++){
        cat[i] = new Cat();
        dog[i] = new Dog();
        cat[i]->makeSound();
        dog[i]->makeSound();
    }
    
    for (int i = 0; i < size; i++){
        delete cat[i];
        delete dog[i];
    }
    return 0; 
}
