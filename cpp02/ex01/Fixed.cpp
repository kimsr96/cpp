/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:04:43 by seungryk          #+#    #+#             */
/*   Updated: 2024/07/04 18:59:53 by seungryk         ###   ########.fr       */
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

Fixed::Fixed(int iNum) : fixedNumber(iNum << bits){
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float fNum) : fixedNumber(roundf(fNum * (1 << bits))){
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) : fixedNumber(copy.fixedNumber){
        std::cout << "Copy constructor called" << std::endl;
};

Fixed &Fixed::operator = (const Fixed &copy){
    if (this != &copy)
        fixedNumber = copy.fixedNumber;
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
};

float   Fixed::toFloat( void ) const{
    return static_cast<float>(fixedNumber) / (1 << bits);
}

int     Fixed::toInt( void ) const{
    return fixedNumber >> bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}