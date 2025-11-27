/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:26:47 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/26 15:26:47 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog: public Animal{
    public:
        Dog();
        Dog(std::string type);
        Dog(const Dog& copy);
        Dog& operator=(const Dog& other);
        virtual ~Dog();
        virtual void makeSound() const;
};
#endif