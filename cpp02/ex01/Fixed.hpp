/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:43:26 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/13 19:23:25 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    private:
        int                 fixedNumber;
        static const int    bits;
    public: 
        Fixed(const int iNum);
        Fixed(const float fNum);
        Fixed();
        ~Fixed();
        Fixed(const Fixed &copy);
        Fixed &operator = (const Fixed &copy);
        int     getRawBits( void ) const;
        void    setRawBits( const int raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif