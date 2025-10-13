#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
        std::string getInput(const std::string prompt);
        static std::string truncateField(std::string field);
        static bool isValidInput(std::string &input);
        static bool isEmpty(std::string field);
        static bool isValidNumber(std::string input);
        

        
    public:
        Contact();
        ~Contact();
        static void fillContact(Contact& contact);
        static void displayContacts(Contact contacts[], int index);

    // Class members and methods go here
};

#endif