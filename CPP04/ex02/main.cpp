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

// Abstract Class cannot be instantiated
// pure virtual function makes a class abstract

int main()
{
    // Animal AA;  
    Animal *animels[4];

    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0) {
            animels[i] = new Dog();
        } else {
            animels[i] = new Cat();
        }
        std::cout << "-------------------------" << std::endl;
    }

    std::cout << "type is " << animels[0]->getType() << std::endl;
    std::cout << "type is " << animels[1]->getType() << std::endl;
    std::cout << "type is " << animels[2]->getType() << std::endl;
    std::cout << "type is " << animels[3]->getType() << std::endl;

    std::cout << "-------------------------" << std::endl;

    std::cout << animels[0]->getIdea(99) << std::endl;
    std::cout << animels[1]->getIdea(0) << std::endl;
    std::cout << animels[2]->getIdea(0) << std::endl;
    std::cout << animels[3]->getIdea(0) << std::endl;

    std::cout << "-------------------------" << std::endl;

    animels[0]->setIdea(99, "New Dog Idea");
    animels[1]->setIdea(0, "New Cat Idea");
    std::cout << animels[0]->getIdea(99) << std::endl;
    std::cout << animels[1]->getIdea(0) << std::endl;

    std::cout << "----------Testing Deep Copy---------------" << std::endl;

    Animal* dog1 = new Dog();
    dog1->setIdea(0, "Dog1 Idea");
    
    std::cout << "-------------------------" << std::endl;

    Animal* dog2 = new Dog(*(static_cast<Dog*>(dog1)));
    std::cout << "-------------------------" << std::endl;

    std::cout << "Dog1 Idea at index 0: " << dog1->getIdea(0) << std::endl;
    std::cout << "Dog2 Idea at index 0: " << dog2->getIdea(0) << std::endl;
    dog2->setIdea(0, "Dog2 New Idea");
    std::cout << "After modifying Dog2's idea:" << std::endl;
    std::cout << "Dog1 Idea at index 0: " << dog1->getIdea(0) << std::endl;
    std::cout << "Dog2 Idea at index 0: " << dog2->getIdea(0) << std::endl;

    std::cout << "-------------------------" << std::endl;
    std::cout << "Deleting dog1 and dog2" << std::endl;
    delete dog1;
    delete dog2;
    

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