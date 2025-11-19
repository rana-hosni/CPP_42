/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:40:04 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/19 10:40:04 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap clap1("Clappy");
    ClapTrap clap2;
    clap1.attack("Target1");
    clap2.takeDamage(5);
    clap1.beRepaired(3);
    clap2.attack("Target2");
    clap1.takeDamage(15);
    clap2.beRepaired(10);
    return 0;
}