/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:02:05 by seungryk          #+#    #+#             */
/*   Updated: 2024/07/01 16:24:27 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class   Zombie {
    public:
        Zombie();
        ~Zombie();
        void announce( void );
        void set_name(std::string name);
        Zombie *newZombie( std::string name );
    private:
        std::string _name;
};

Zombie  *newZombie( std::string name );
void    randomChump( std::string name );
Zombie  *zombiHorde( int N, std::string name);