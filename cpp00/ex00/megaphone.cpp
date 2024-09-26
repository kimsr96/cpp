/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:09:52 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/09 20:00:32 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv) {
  int i;
  int j;

  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  else {
    i = 1;
    while (argv[i]) {
      j = 0;
      while (argv[i][j]) {
        argv[i][j] = toupper(argv[i][j]);
        j++;
      }
      std::cout << argv[i];
      i++;
    }
    std::cout << std::endl;
  }
}
