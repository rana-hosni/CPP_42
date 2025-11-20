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

int main() {
    ScavTrap scav("R2D2");
    FragTrap frag("FRAG");
    scav.attack("C3PO");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();
    frag.attack("C3PO");
    frag.takeDamage(30);
    frag.beRepaired(20);
    frag.highFivesGuys();
    return 0;
}