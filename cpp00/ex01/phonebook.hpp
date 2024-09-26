/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:56:51 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/10 15:44:46 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iomanip>

class PhoneBook{
	public:
		Contact contacts[8];
		PhoneBook();
		~PhoneBook();
		void add_contact(int idx);
		void search_contact(int idx);
		void show_contact(int idx);
		void display_all(int idx);
};

#endif
