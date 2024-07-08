/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:43:26 by seungryk          #+#    #+#             */
/*   Updated: 2024/07/08 16:59:05 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
    private:
        int                 fixedNumber;
        static const int    bits;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &copy);
        Fixed &operator = (const Fixed &copy);
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
};

#endif