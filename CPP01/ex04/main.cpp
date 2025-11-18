/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:17:36 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/06 11:51:07 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.hpp"

void testmood(std::string fileName)
{
    std::string s1 = "HELLO";
    std::string s2 = "HI";
    File fileobj(fileName);
    fileobj.replaceContent(s1, s2);
    
}

int main(int argc, char** argv)
{
    std::string fileName;
    std::string s1;
    std::string s2;

    if (argc == 2)
    {
        fileName = argv[1];
        if (isspace(fileName[0]))
        {
            std::cerr << "Error: File name cannot be empty or start with whitespace." << std::endl;
            return 1;
        }
        std::cout << "Enter the first string to replace: ";
        std::getline(std::cin, s1);
        std::cout << "Enter the second string to replace: ";
        std::getline(std::cin, s2);
        if (s1.empty())
        {
            std::cerr << "Error: Strings to replace cannot be empty." << std::endl;
            return 1;
        }
        File fileobj(fileName);
        fileobj.replaceContent(s1, s2);
    }
    else if (argc == 1)
    {
        testmood("./files/text");
        testmood("./files/empty");
        testmood("./files/newline");
    }
    else
        std::cerr << " wrong number of arguments" << std::endl;
    
    return 0;
}