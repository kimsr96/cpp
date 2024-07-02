/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:50:06 by seungryk          #+#    #+#             */
/*   Updated: 2024/07/02 14:07:46 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    std::ifstream   inFile;
    std::ofstream   outFile;
    std::string     fileName;
    std::string     line;

    if (argc != 2)
        return (0);
    else
    {
        inFile.open(argv[1]);
        if (inFile.is_open())
        {
            fileName = inFile + ".replace";
            outFile.open(fileName);
            while (std::getline(fileName, line)){
                outFile << line << std::endl;
            }
            inFile.close();
            outFile.close();
        }
        else
            std::cerr << "File error" << std::endl;  
    }
}
