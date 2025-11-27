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
#include "Brain.hpp"


int main()
{
    Animal *animels[4];
    // std::cout << "-------------------------" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0) {
            animels[i] = new Dog();
        } else {
            animels[i] = new Cat();
        }
        std::cout << "-------------------------" << std::endl;
    }

    std::cout << " TESTING IDEAS  " << std::endl; 
    for (int k = 0; k < 4; k++) {
        animels[k]->getType();
        animels[k]->makeSound();
        for (int j = 0; j < 100; j++) {
            std::cout << animels[k]->getIdea(j) << std::endl;
        }
    }

    std::cout << "-------------------------" << std::endl;
    for (int i = 0; i < 4; i++) {
        delete animels[i];
        std::cout << "-------------------------" << std::endl;
    }
    
    return 0;

}

// int main()
// {
// const Animal *animal = new Animal();
// const Animal* dog = new Dog();
// const Animal* cat = new Cat();
// std::cout << "Type is : " << dog->getType() << std::endl;
// std::cout << "Type is : " << cat->getType() << std::endl;
// cat->makeSound(); //will output the cat sound!
// dog->makeSound();
// animal->makeSound();


// const WrongAnimal* wrongAnimal = new WrongAnimal();
// const WrongAnimal* wrongCat = new WrongCat();
// std::cout << "Type is : " << wrongCat->getType() << std::endl;
// wrongCat->makeSound(); //will output the wrong animal sound!
// wrongAnimal->makeSound();

// delete animal;
// delete dog;
// delete cat;
// delete wrongAnimal;
// delete wrongCat;
// return 0;
// }