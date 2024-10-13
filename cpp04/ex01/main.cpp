/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:42:46 by seungryk          #+#    #+#             */
/*   Updated: 2024/10/13 14:06:29 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <stdlib.h>

//void    check_leaks(void)
//{
//    system("leaks a.out");
//}

int main() 
{
    //atexit(check_leaks);

    const Animal* j = new Dog(); 
    const Animal* i = new Cat();
    delete j;//should not create a leak 
    delete i;
    
    int size = 10;
    Animal *animals[size];
    for (int i = 0; i < size; i++){
        if (i < size / 2)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }
    
    for (int i = 0; i < size; i++){
        animals[i]->makeSound();
    }

    //deep copy test
    std::cout << "==============" << std::endl;
    std::cout << "DEEP COPY TEST" << std::endl;
    std::cout << "==============" << std::endl;

    Cat *original = new Cat();
    Cat *copy = new Cat();
    //copy = original;
    original->setBrainIdeas("original_");
    copy->setBrainIdeas("copy_");
    
    std::cout << "==============" << std::endl;
    std::cout << "Before Copy" << std::endl;
    std::cout << "==============" << std::endl;
    
    std::cout << original->getBrainIdeas(1) << std::endl;
    std::cout << copy->getBrainIdeas(1) << std::endl;
    
    std::cout << "==============" << std::endl;
    std::cout << "After Copy" << std::endl;
    std::cout << "==============" << std::endl;

    *copy = *original;
    std::cout << original->getBrainIdeas(1) << std::endl;
    std::cout << copy->getBrainIdeas(1) << std::endl; 
    std::cout << "==============" << std::endl;
    delete original;
    delete copy;

    for (int i = 0; i < size; i++){
        delete animals[i];
    }
    
    return 0; 
}
