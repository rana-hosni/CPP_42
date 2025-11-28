/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:12:12 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/26 15:12:12 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& copy);
        Animal& operator=(const Animal& other);
        virtual ~Animal() = 0;
        virtual void makeSound() const = 0;

        std::string getType() const;
        virtual std::string getIdea(int index) const = 0;
        virtual void setIdea(int index, const std::string& idea) = 0;


};

#endif