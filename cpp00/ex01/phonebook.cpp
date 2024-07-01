/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:11:43 by seungryk          #+#    #+#             */
/*   Updated: 2024/06/28 16:12:07 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void) {
  Phonebook   pb;
  Contact     contact[8];
  std::string input;
  int         idx;
  int         num;
  int         search_idx;

  idx = 0;
  while (true) {
    std::cout << "[ADD], [SEARCH], [EXIT]" << std::endl;
    std::cin >> input;
    if (input == "ADD")
    {
      pb.add_contact(idx); 
      idx++;
    }
    else if (input == "SEARCH")
    {
      if (idx == 0)
        std::cout << "Phonebook is empty !" << std::endl;
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
          std::cout << "Invalid Command" << std::endl;
          std::cin.clear(); // cin의 상태를 재설정
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
          continue ;
        }
        if (search_idx >= num)
          std::cout << "We don't have that ID" << std::endl;
        else
          pb.search_contact(search_idx);
      }
    }
    else if (input == "EXIT")
      break ;
    else
      std::cout << "Invalid Command" << std::endl;
  }
}
