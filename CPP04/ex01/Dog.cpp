/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:26:39 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/26 15:26:39 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog(): brain(new Brain("Paw Idea")) {
    this->_type = "Dog";
    std::cout << "Calling Dog Default Constructor" << std::endl;
}

Dog::Dog(std::string type): brain(new Brain("Paw Idea")) {
    this->_type = type;
    std::cout << "Calling Dog Parameterized Constructor" << std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy){
    this->_type = copy._type;
    this->brain = new Brain(*copy.brain);
    std::cout << "Calling Dog Copy Constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other){
        this->_type = other._type;
        delete brain;
        brain = new Brain(*other.brain);

    }
    std::cout << "Calling Dog Copy Assignment Operator" << std::endl;
    return *this;
}

Dog::~Dog(){
    std::cout << "Calling Dog Destructor" << std::endl;
    delete brain;
}

void Dog::makeSound() const{
    std::cout << "Woof Woof" << std::endl;
}
