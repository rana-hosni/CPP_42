/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:14:14 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/26 15:14:14 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
//     Animal animal;
//     std::cout << "Animal Type: " << animal.getType() << std::endl;
//     animal.makeSound();

//     Dog dog;
//     std::cout << "Dog Type: " << dog.getType() << std::endl;
//     dog.makeSound();

//     Cat cat;
//     std::cout << "Cat Type: " << cat.getType() << std::endl;
//     cat.makeSound();
//     return 0;

// }

int main()
{
const Animal *animal = new Animal();
const Animal* dog = new Dog();
const Animal* cat = new Cat();
std::cout << dog->getType() << std::endl;
std::cout << cat->getType() << std::endl;
cat->makeSound();
dog->makeSound();
animal->makeSound();

std::cout << "----- Wrong Animal Test -----" << std::endl;
const WrongAnimal* wrongAnimal = new WrongAnimal();
const WrongAnimal* wrongCat = new WrongCat();
std::cout << wrongCat->getType() << std::endl;
wrongCat->makeSound();
wrongAnimal->makeSound();

std::cout << "----- Cleaning Up -----" << std::endl;
delete animal;
delete dog;
delete cat;
delete wrongAnimal;
delete wrongCat;
return 0;
}