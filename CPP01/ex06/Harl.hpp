/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:06:10 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/04 14:58:48 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <sstream>

class Harl
{
    public:
        Harl();
        ~Harl();
        void complain( std::string level );
        int filterLevel(std::string level);

    private:
        void debug();
        void info();
        void warning();
        void error();
        
};

#endif