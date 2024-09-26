 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:04:43 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/13 18:36:12 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (fixedNumber);
}

void    Fixed::setRawBits( int const raw ){
    fixedNumber = raw;
}

Fixed::Fixed() : fixedNumber(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int iNum) : fixedNumber(iNum << bits){
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fNum) : fixedNumber(roundf(fNum * (1 << bits))){
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &copy){
    if (this != &copy)
        fixedNumber = copy.fixedNumber;
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
};

Fixed::Fixed(const Fixed &copy){
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
};


float   Fixed::toFloat( void ) const{
    return stati_cast<float>(fixedNumber) /c (1 << bits);
}

int     Fixed::toInt( void ) const{
    return fixedNumber >> bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
