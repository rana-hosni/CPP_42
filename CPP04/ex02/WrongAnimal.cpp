/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:48:10 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/27 11:49:41 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("WrongAnimal"){
    std::cout << "Calling WrongAnimal Default Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type){
    std::cout << "Calling WrongAnimal Parameterized Constructor" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& copy){
    this->_type = copy._type;
    std::cout << "Calling WrongAnimal Copy Constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    if (this != &other){
        this->_type = other._type;
    }
    std::cout << "Calling WrongAnimal Copy Assignment Operator" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "Calling WrongAnimal Destructor" << std::endl;
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal Sound" << std::endl;
}

std::string WrongAnimal::getType() const{
    return this->_type;
}