/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:17:36 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/03 15:59:49 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.hpp"

int main()
{
    std::string fileName;
    std::string s1;
    std::string s2;

    std::cout << "Enter the file name: ";
    std::getline(std::cin, fileName);
    if (fileName.empty() || isspace(fileName[0]))
    {
        std::cerr << "Error: File name cannot be empty or start with whitespace." << std::endl;
        return 1;
    }
    std::cout << "Enter the first string to replace: ";
    std::getline(std::cin, s1);
    std::cout << "Enter the second string to replace: ";
    std::getline(std::cin, s2);
    if (s1.empty() || s2.empty())
    {
        std::cerr << "Error: Strings to replace cannot be empty." << std::endl;
        return 1;
    }
    File fileobj(fileName);
    fileobj.replaceContent(s1, s2);
    return 0;
}