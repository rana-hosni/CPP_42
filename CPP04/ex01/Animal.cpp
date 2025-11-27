/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:13:22 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/26 15:13:22 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Animal"){
    std::cout << "Calling Animal Default Constructor" << std::endl;
}

Animal::Animal(std::string type): _type(type){
    std::cout << "Calling Animal Parameterized Constructor" << std::endl;
}

Animal::Animal(const Animal& copy){
    this->_type = copy._type;
    std::cout << "Calling Animal Copy Constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other){
    if (this != &other){
        this->_type = other._type;
    }
    std::cout << "Calling Animal Copy Assignment Operator" << std::endl;
    return *this;
}

Animal::~Animal(){
    std::cout << "Calling Animal Destructor" << std::endl;
}

void Animal::makeSound() const{
    std::cout << "Animal Sound" << std::endl;
}

std::string Animal::getType() const{
    return this->_type;
}

std::string Animal::getIdea(int index) const{
    (void)index;
    return "";
}
