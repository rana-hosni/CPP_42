/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:41:02 by relgheit          #+#    #+#             */
/*   Updated: 2025/10/29 15:00:41 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main()
{
    std::string zombieName;
    Zombie* zombie = newZombie("ROOO");
    zombie->announce();
    delete zombie;
    std::cout << "Enter name for randomChump: ";
    std::cin >> zombieName;
    randomChump(zombieName);
    return 0;
}