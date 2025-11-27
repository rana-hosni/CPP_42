/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:28:55 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/26 15:28:55 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat: public Animal{
    public:
        Cat();
        Cat(std::string type);
        Cat(const Cat& copy);
        Cat& operator=(const Cat& other);
        virtual ~Cat();
        virtual void makeSound() const;
};

#endif