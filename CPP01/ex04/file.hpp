/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:22:05 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/03 12:48:12 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <string>
#include <fstream>

class File
{
    public:
        File(const std::string& fileName);
        ~File();
        void replaceContent(const std::string& s1, const std::string& s2);
        
    private:
        std::string _fileName;
        bool openFile();
};

#endif