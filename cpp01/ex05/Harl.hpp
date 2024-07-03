/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:25:52 by seungryk          #+#    #+#             */
/*   Updated: 2024/07/03 12:41:38 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl{
    private:
        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void );
    public:
        Harl();
        ~Harl();
        void    complain( std::string level );
};

#endif