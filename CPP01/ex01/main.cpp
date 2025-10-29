/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:09:41 by relgheit          #+#    #+#             */
/*   Updated: 2025/10/29 17:21:32 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

int main()
{
    std::string zombieName;
    int N;
    std::cout << "Enter number of zombies in the horde: ";
    std::cin >> N;
    std::cout << "Enter name for the zombies: ";
    std::cin >> zombieName;
    Zombie* horde = zombieHorde(N, zombieName);
    for (int i = 0; i < N; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}