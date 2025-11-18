/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:22:08 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/06 11:28:03 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.hpp"

File::File(const std::string& fileName) : _fileName(fileName)
{
}

File::~File()
{
}
bool File::openFile()
{
    std::ifstream file(_fileName.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << _fileName << std::endl;
        return false;
    }
    file.close();
    return true;
}
void File::replaceContent(const std::string& s1, const std::string& s2)
{
    if (!openFile())
        return;
    std::ifstream inputFile(_fileName.c_str());
    std::string content;
    std::string oFile;
    oFile = _fileName + ".replace";
    std::ofstream outputFile(oFile.c_str(), std::ios::app);
    while (std::getline(inputFile, content))
    {
        size_t pos = 0;
        while ((pos = content.find(s1, pos)) != std::string::npos)
        {
            content.erase(pos, s1.length());
            content.insert(pos, s2);
            pos += s2.length();
        }
        outputFile << content;
        if (!inputFile.eof())
            outputFile << std::endl;
    }
    inputFile.close();
    std::cout << s1 << " replaced with " << s2 << " in result.txt" << std::endl;
    outputFile.close();
    return;
}