/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:28:31 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/26 15:28:31 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): brain(new Brain("Meow Idea")) {
    this->_type = "Cat";
    std::cout << "Calling Cat Default Constructor" << std::endl;
}

Cat::Cat(std::string type): brain(new Brain("Meow Idea")) {
    this->_type = type;
    std::cout << "Calling Cat Parameterized Constructor" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy){
    this->_type = copy._type;
    this->brain = new Brain(*copy.brain);
    std::cout << "Calling Cat Copy Constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other){
        this->_type = other._type;
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Calling Cat Copy Assignment Operator" << std::endl;
    return *this;
}

Cat::~Cat(){
    std::cout << "Calling Cat Destructor" << std::endl;
    delete brain;
}

void Cat::makeSound() const{
    std::cout << "Meow Meow" << std::endl;
}
