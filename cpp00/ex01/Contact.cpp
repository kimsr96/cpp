/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:37:00 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/10 15:59:23 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
}

Contact::~Contact(){
}

void Contact::setIndex(int idx){
    this->index = idx;
}

void Contact::setFirstName(std::string input){
    this->first_name = input;
}

void Contact::setLastName(std::string input){
    this->last_name = input;
}

void Contact::setNickName(std::string input){
    this->nick_name = input;
}

void Contact::setPhoneNumber(std::string input){
    this->phone_number = input;
}

void Contact::setDarkestSecret(std::string input){
    this->darkest_secret = input;
}

int Contact::getIndex(void){
    return (index);
}

std::string Contact::getFirstName(void){
    return (first_name);
}

std::string Contact::getLastName(void){
    return (last_name);
}

std::string Contact::getNickName(void){
    return (nick_name);
}

std::string Contact::getPhoneNumber(void){
    return (phone_number);
}

std::string Contact::getDarkestSecret(void){
    return (darkest_secret);
}
