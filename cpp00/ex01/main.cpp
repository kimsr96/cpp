/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:35:23 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/10 16:01:01 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void) 
{
  PhoneBook   pb;
  Contact     contact[8];
  std::string input;
  int         idx;
  int         num;
  int         search_idx;

  idx = 0;
  while (true) {
    std::cout << "[ADD], [SEARCH], [EXIT]" << std::endl;
    if (!std::getline(std::cin, input)) 
    {
        if (std::cin.eof()) 
            std::cout << "EXIT" << std::endl;
        break;
    }
    if (input.compare("ADD") == 0)
    {
      pb.add_contact(idx); 
      idx++;
    }
    else if (input.compare("SEARCH") == 0)
    {
      if (idx == 0)
        std::cerr << "Phonebook is empty !" << std::endl;
      else
      {
        if (idx > 7)
          num = 8;
        else
          num = idx;
        pb.display_all(num);
        std::cout << "We have " << num << " contacts, ";
        std::cout << "Which index to search?" << std::endl;
        std::cin >> search_idx;
        if (std::cin.fail())
        {
          std::cerr << "Invalid Command" << std::endl;
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          continue ;
        }
        if (search_idx >= num)
          std::cerr << "We don't have that ID" << std::endl;
        else
          pb.search_contact(search_idx);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
    }
    else if (input.compare("EXIT") == 0)
      break ;
    else
      std::cerr << "Invalid Command" << std::endl;
  }
  return (0);
}
