/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:05:32 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/04 15:18:06 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;
    std::string mood;
    if (argc != 2)
    {
        std::cout << "use only one argument" << std::endl;
        return 1;
    }
    else
        mood = argv[1];
    harl.complain(mood);
    return 0;
}