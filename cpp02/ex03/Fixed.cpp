/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:04:43 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/14 19:38:29 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

const int Fixed::bits = 8;

int Fixed::getRawBits( void ) const{
    return (fixedNumber);
}

void    Fixed::setRawBits( int const raw ){
    fixedNumber = raw;
}

Fixed::Fixed() : fixedNumber(0){
}

Fixed::Fixed(const int iNum) : fixedNumber(iNum << bits){
}

Fixed::Fixed(const float fNum) : fixedNumber(roundf(fNum * (1 << bits))){
}

Fixed::~Fixed(){
}

Fixed::Fixed(const Fixed &copy) : fixedNumber(copy.fixedNumber){
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

Fixed &Fixed::operator=(const Fixed &copy){
    if (this != &copy)
        fixedNumber = copy.fixedNumber;
    return (*this);
};

bool Fixed::operator>(const Fixed& fixed) const {
    return (this->fixedNumber > fixed.fixedNumber);
}

bool Fixed::operator<(const Fixed& fixed) const {
    return (this->fixedNumber < fixed.fixedNumber);
}

bool Fixed::operator>=(const Fixed& fixed) const {
    return (this->fixedNumber >= fixed.fixedNumber);
}

bool Fixed::operator<=(const Fixed& fixed) const {
    return (this->fixedNumber <= fixed.fixedNumber);
}

bool Fixed::operator==(const Fixed& fixed) const {
    return (this->fixedNumber == fixed.fixedNumber);
}

bool Fixed::operator!=(const Fixed& fixed) const {
    return (this->fixedNumber != fixed.fixedNumber);
}

Fixed Fixed::operator+(const Fixed& fixed) const {
    return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed& fixed) const {
    return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed& fixed) const {
    return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed& fixed) const {
    return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed& Fixed::operator++() {
    this->fixedNumber++;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return (temp);
}

Fixed& Fixed::operator--() {
    this->fixedNumber--;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return (temp);
}

Fixed &Fixed::min(Fixed &num1, Fixed &num2)
{
    if (num1 >= num2)
        return (num2);
    else
        return (num1);    
}

const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2)
{
    if (num1 >= num2)
        return (num2);
    else
        return (num1);
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2)
{
    if (num1 >= num2)
        return (num1);
    else
        return (num2);   
}

const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2)
{
    if (num1 >= num2)
        return (num1);
    else
        return (num2);
}

