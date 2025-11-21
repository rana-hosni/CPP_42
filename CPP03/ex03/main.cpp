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
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    ClapTrap clap("Clappy");
    ScavTrap scav("Scavvy");
    FragTrap frag("Fraggy");
    DiamondTrap diamond("Diamond");
    clap.attack("Target1");
    scav.attack("Target2");
    frag.attack("Target3");
    scav.guardGate();
    frag.highFivesGuys();
    diamond.attack("Target4");
    return 0;
}