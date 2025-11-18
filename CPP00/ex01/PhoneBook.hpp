#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "Contact.hpp"


class  PhoneBook
{
     private:
     int currentIndex;
     void Add(void);
     void Search(void);


     public:
          PhoneBook();
          ~PhoneBook();
          Contact contacts[8];
          int Run(void);
};

#endif