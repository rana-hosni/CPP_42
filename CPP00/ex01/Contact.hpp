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
        std::string GetInput(const std::string prompt);
        static std::string TruncateField(std::string field);
        static bool IsValidInput(std::string &input);
        static bool IsEmpty(std::string field);
        static bool IsValidNumber(std::string input);


        
    public:
        Contact();
        ~Contact();
        static void FillContact(Contact& contact);
        static void DisplayContacts(Contact contacts[8], int index);

    // Class members and methods go here
};

#endif