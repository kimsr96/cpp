/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:04:43 by seungryk          #+#    #+#             */
/*   Updated: 2024/07/08 17:14:36 by seungryk         ###   ########.fr       */
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

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) : fixedNumber(copy.fixedNumber){
        std::cout << "Copy constructor called" << std::endl;
        *this = copy;
};

Fixed &Fixed::operator = (const Fixed &copy){
    std::cout << "Copy assignment operator called" << std::endl;
    fixedNumber = copy.fixedNumber;
    copy.getRawBits();
    return (*this);
};