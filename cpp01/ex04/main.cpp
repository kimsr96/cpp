/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:50:06 by seungryk          #+#    #+#             */
/*   Updated: 2024/07/03 12:01:50 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    std::ifstream   inFile;
    std::ofstream   outFile;
    std::string     line;
    size_t          idx;

    if (argc != 4)
        return (0);
    inFile.open(argv[1]);
    if (!inFile.is_open())
        return (1);
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string fileName = std::string(argv[1]) + ".replace";
    outFile.open(fileName);
    if (!outFile.is_open())
    {
        inFile.close();
        return (1);
    }
    while (std::getline(inFile, line)){
        if ((idx = line.find(s1)) == std::string::npos)
            outFile << line << std::endl;
        else
        {
            line.erase(idx, s1.length());
            line.insert(idx, s2);
            outFile << line << std::endl;
        }
    }
    inFile.close();
    outFile.close();
}
