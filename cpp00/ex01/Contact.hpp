/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:37:00 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/10 15:55:08 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
 private:
	int         index;
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

 public:
    void setIndex(int idx);
    void setFirstName(std::string input);
    void setLastName(std::string input);
    void setNickName(std::string input);
    void setPhoneNumber(std::string input);
    void setDarkestSecret(std::string input);
    int getIndex(void);
    std::string getFirstName(void);
    std::string getLastName(void);
    std::string getNickName(void);
    std::string getPhoneNumber(void);
    std::string getDarkestSecret(void);
	Contact();
	~Contact();
};

#endif
