/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:48:02 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/27 11:58:11 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(){
    this->_type = "WrongCat";
    std::cout << "Calling WrongCat Default Constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other){
    this->_type = other._type;
    std::cout << "Calling WrongCat Copy Constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other){
    if (this != &other){
        this->_type = other._type;
    }
    std::cout << "Calling WrongCat Copy Assignment Operator" << std::endl;
    return *this;
}

WrongCat::~WrongCat(){
    std::cout << "Calling WrongCat Destructor" << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << "Meow Meow (WrongCat Sound)" << std::endl;
}

