#include "Contact.hpp"

Contact::Contact()
{
    return;
}

Contact::~Contact()
{
    return;
}


std::string Contact::truncateField(std::string field)
{
    std::string truncated = field;
    if (field.length() > 10)
    {
        truncated = field.substr(0, 9) + ".";
        return truncated;
    }
    return field;
}

void Contact::displayContacts(Contact contacts[8], int index)
{
    std::cout << "Displaying contacts..." << std::endl;

    if (index == -1)
    {
        std::cout << std::setw(10) << truncateField("Index") << " | "
                  << std::setw(10) << truncateField("First Name") << " | "
                  << std::setw(10) << truncateField("Last Name") << " | "
                  << std::setw(10) << truncateField("Nickname") << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
        for (int i = 0; i < 8; i++)
        {
            std::cout << std::setw(10) << i
                    << " | " << std::setw(10) << truncateField(contacts[i].firstName)
                    << " | " << std::setw(10) << truncateField(contacts[i].lastName)
                    << " | " << std::setw(10) << truncateField(contacts[i].nickname) << std::endl;
        }
    }
    else if (index >= 0 && index < 8)
    {
        if (contacts[index].firstName.empty())
        {
            std::cout << "No contact found at index " << index << "." << std::endl;
            return;
        }
        std::cout << "First Name: " << truncateField(contacts[index].firstName) << std::endl;
        std::cout << "Last Name: " << truncateField(contacts[index].lastName) << std::endl;
        std::cout << "Nickname: " << truncateField(contacts[index].nickname) << std::endl;
        std::cout << "Phone Number: " << truncateField(contacts[index].phoneNumber) << std::endl;
    }
    else
    {
        std::cout << "Invalid index or contact does not exist." << std::endl;
    }
}


bool Contact::isValidInput(std::string &input)
{
    // size_t found;
    // std::string markWord = "Phone";

    if (input.empty())
    {
        std::cout << "Input cannot be empty." << std::endl;
        return false;
    }
    // found = input.find(markWord);
    // std::cout << "Debug: found = " << found << std::endl; // Debugging line
    // if (found != std::string::npos)
    // {
        for (size_t i = 0; i < input.length(); i++)
        {
            if (!isalnum(static_cast<unsigned char>(input[i])) 
            && !isspace(static_cast<unsigned char>(input[i])) 
            && input[i] != '-' && input[i] != '_' && input[i] != '.')
            {
                std::cout << "Invalid character detected: '" << input[i] << "'. Please use only alphanumeric characters, spaces, hyphens, underscores, or periods." << std::endl;
                return false;
            }
        }
    // }
    // else
    // {
    //     for (size_t i = 0; i < input.length(); i++)
    //     {
    //         if (i == 0 && (input[i] == '+'))
    //             continue;
    //         if (!isdigit(static_cast<unsigned char>(input[i])))
    //         {
    //             std::cout << "Invalid character detected: '" << input[i] << "'. Please enter only numeric characters." << std::endl;
    //             return false;
    //         }
    //     }
    // }
    return true;
}

std::string Contact::getInput(const std::string prompt)
{
    std::string input;
    size_t found;
    std::string markWord = "Phone";

    found = input.find(markWord);
    
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cout << "\nEnd of input detected. Exiting the program." << std::endl;
            std::exit(1);
        }
        if (found == std::string::npos)
        {
            for (size_t i = 0; i < input.length(); i++)
            {
                if (i == 0 && (input[i] == '+'))
                    continue;
                if (!isdigit(static_cast<unsigned char>(input[i])))
                {
                    std::cout << "Invalid character detected: '" << input[i] << "'. Please enter only numeric characters." << std::endl;
                    input.clear();
                    break;
                }
            }
        }
        if (isValidInput(input))
            return input;
    }
    return input;
}

void Contact::fillContact(Contact& contact)
{
    contact.firstName = contact.getInput("Enter First Name: ");
    contact.lastName = contact.getInput("Enter Last Name: ");
    contact.nickname = contact.getInput("Enter Nickname: ");
    contact.phoneNumber = contact.getInput("Enter Phone Number: ");
    contact.darkestSecret = contact.getInput("Enter Darkest Secret: ");
}
