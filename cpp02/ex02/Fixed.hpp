/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:43:26 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/13 19:20:46 by seungryk         ###   ########.fr       */
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
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;

        bool operator>(const Fixed& fixed) const;
        bool operator<(const Fixed& fixed) const;
        bool operator>=(const Fixed& fixed) const;
        bool operator<=(const Fixed& fixed) const;       
        bool operator==(const Fixed& fixed) const;
        bool operator!=(const Fixed& fixed) const;
        
        Fixed operator+(const Fixed& fixed) const;
        Fixed operator-(const Fixed& fixed) const;
        Fixed operator*(const Fixed& fixed) const;
        Fixed operator/(const Fixed& fixed) const;

        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);

        static  Fixed &min(Fixed &num1, Fixed &num2);
        static const Fixed &min(const Fixed &num1, const Fixed &num2);
        static  Fixed &max(Fixed &num1, Fixed &num2);
        static const Fixed &max(const Fixed &num1, const Fixed &num2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif