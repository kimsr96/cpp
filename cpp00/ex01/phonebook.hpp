/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:56:51 by seungryk          #+#    #+#             */
/*   Updated: 2024/06/28 16:28:48 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact {
 public:
  int         index;
  std::string first_name;
  std::string last_name;
  std::string nick_name;
  std::string phone_number;
  std::string darkest_secret;
  Contact();
  ~Contact();
};

Contact::Contact(){
}

Contact::~Contact(){
}

class Phonebook{
  public:
    Contact contacts[8];
    Phonebook();
    ~Phonebook();
    void add_contact(int idx);
    void search_contact(int idx);
    void show_contact(int idx);
    void display_all(int idx);
};

Phonebook::Phonebook(){ 
}

Phonebook::~Phonebook(){
}

void Phonebook::add_contact(int idx){
  contacts[idx % 8].index = idx % 8;
  
  std::cout << "first_name : ";
  std::cin >> contacts[idx % 8].first_name;
  
  std::cout << "last_name : ";
  std::cin >> contacts[idx % 8].last_name;
  
  std::cout << "nick_name : ";
  std::cin >> contacts[idx % 8].nick_name;

  std::cout << "phone_number : ";
  std::cin >> contacts[idx % 8].phone_number;

  std::cout << "darkest_secret : ";
  std::cin >>  contacts[idx % 8].darkest_secret;
}

std::string ten_char(std::string input)
{
  std::string ret;
  
  if (input.size() > 10)
    ret = input.substr(0, 9) + '.';
  else
    ret = input;
  return (ret);
}

void Phonebook::show_contact(int idx)
{
  Contact contact;
  
  contact = contacts[idx];
  std::cout << "|" << std::setw(10) << contact.index;
  std::cout << " | " << std::setw(10) << ten_char(contact.first_name);
  std::cout << " | " << std::setw(10) << ten_char(contact.last_name);
  std::cout << " | " << std::setw(10) << ten_char(contact.nick_name) << " |" << std::endl;
}

void  Phonebook::search_contact(int idx)
{
  if (idx < 0 || idx > 7)
     std::cout << "Invalid Index" << std::endl;
  std::cout << " -------------------------------------------------- " << std::endl;
  show_contact(idx);
  std::cout << " -------------------------------------------------- " << std::endl;
}

void  Phonebook::display_all(int idx)
{
  int i;

  i = 0;
  std::cout << " -------------------------------------------------- " << std::endl;
  std::cout << "|   index   | first name |  last name |  nick name |" << std::endl;
  std::cout << " -------------------------------------------------- " << std::endl;
  while (i < idx)
  {
    show_contact(i);
    std::cout << " -------------------------------------------------- " << std::endl;
    i++;
  }
}
#endif