/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:11:43 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/11 16:02:05 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){ 
}

PhoneBook::~PhoneBook(){
}

std::string valid_string(void)
{
	bool										err;
	std::string							input;
	std::string::size_type 	i;

	while (true)
	{
		i = 0;
		err = false;
		std::getline(std::cin, input);
		while (i < input.size())
		{
			if (!isprint((unsigned char)input[i]))
			{
				err = true;
				std::cout << "Wrong input. Please try again" << std::endl;
				break ;
			}
			i++;
		}
		if (!err)
			break ;
	}
	return (input);
}

std::string valid_number(void)
{
	bool					err;
	std::string				input;
	std::string::size_type 	i;

	while (true)
	{
		i = 0;
		err = false;
		std::getline(std::cin, input);
		while (i < input.size())
		{
			if (!isdigit(input[i]))
			{
				err = true;
				std::cout << "Wrong input. Please try again" << std::endl;
				break ;
			}
			i++;
		}
		if (!err)
			break ;
	}
	return (input);
}

void PhoneBook::add_contact(int idx){
	std::string input;

	contacts[idx % 8].setIndex(idx % 8);
	
	std::cout << "first_name : ";
	contacts[idx % 8].setFirstName(valid_string());

	std::cout << "last_name : ";
	contacts[idx % 8].setLastName(valid_string());
	
	std::cout << "nick_name : ";
	contacts[idx % 8].setNickName(valid_string());

	std::cout << "phone_number : ";
	contacts[idx % 8].setPhoneNumber(valid_number());

	std::cout << "darkest_secret : ";
	contacts[idx % 8].setDarkestSecret(valid_string());
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

void PhoneBook::show_contact(int idx)
{
	Contact contact;
	
	contact = contacts[idx];
	std::cout << "|" << std::setw(10) << contact.getIndex();
	std::cout << " | " << std::setw(10) << ten_char(contact.getFirstName());
	std::cout << " | " << std::setw(10) << ten_char(contact.getLastName());
	std::cout << " | " << std::setw(10) << ten_char(contact.getNickName()) << " |" << std::endl;
}

void  PhoneBook::search_contact(int idx)
{
  Contact contact;
	
  if (idx < 0 || idx > 7)
  {
	std::cout << "Invalid Index" << std::endl;
    return ;
  }
	contact = contacts[idx];
    std::cout << std::endl << "First name : " << contact.getFirstName() << std::endl;
	std::cout << "Last name : " << contact.getLastName() << std::endl;
	std::cout << "Nick name : " << contact.getNickName() << std::endl;
	std::cout << "Contact : " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest_secret : " << contact.getDarkestSecret() << std::endl << std::endl;
}

void  PhoneBook::display_all(int idx)
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
