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

int main() {
    ScavTrap scav("R2D2");
    scav.attack("C3PO");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();
    return 0;
}