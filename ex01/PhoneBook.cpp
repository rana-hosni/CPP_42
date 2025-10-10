#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : currentIndex(0)
{
    return;
}

PhoneBook::~PhoneBook()
{
    return;
}


int PhoneBook::run(void)
{
    std::string command;

    currentIndex = 0; // Initialize currentIndex
    while (true)
    {

        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
    
        if (command == "ADD")
            add();
        else if (command == "SEARCH")
            search();
        else if (command == "EXIT")
        {
            std::exit(0);
        }
        else
        {
            if (std::cin.eof())
            {
                std::cout << "\nEnd of input detected. Exiting the program." << std::endl;
                std::exit(1);
            }
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
    return 0;
}

void PhoneBook::add(void)
{
    std::cout << "Adding a contact..." << std::endl;
    
    Contact::fillContact(contacts[currentIndex]);
    currentIndex = (currentIndex + 1) % 8; // Wrap around after 8 contacts
    
}

void PhoneBook::search(void)
{
    std::string input;
    int index;
    
    Contact::displayContacts(contacts, -1);
    std::cout << "Enter the index of the contact to view details: ";
    std::getline(std::cin, input);
    if (std::cin.eof())
    {
        std::cout << "\nEnd of input detected. Exiting the program." << std::endl;
        std::exit(1);
    }
    if (input.length() == 1 && isdigit(input[0]))
    {
        index = input[0] - '0';
        if (index < 0 || index > 7)
        {
            std::cout << "Invalid index. Please enter a number between 0 and 7." << std::endl;
            return;
        }
        Contact::displayContacts(contacts, index);
    }
    else
        std::cout << "Invalid index. Please enter a number between 0 and 7." << std::endl;

}
