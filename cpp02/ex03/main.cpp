/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:42:46 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/14 21:03:26 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

int main(void)
{
    bool        result;
    const Point a(Fixed(4), Fixed(5));
    const Point b(Fixed(-3), Fixed(-4));
    const Point c(Fixed(5), Fixed(0));
    const Point p(Fixed(2), Fixed(0));
    
    result = bsp(a, b, c, p);
    if (result == true)
        std::cout << "point is in 3 points" << std::endl;
    else
        std::cout << "point in out of points" << std::endl; 
    return 0;
}
