/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:21:34 by relgheit          #+#    #+#             */
/*   Updated: 2025/10/15 12:45:55 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
    return;
}

Contact::~Contact()
{
    return;
}
    
bool Contact::IsEmpty(std::string field)
{
    for (size_t i = 0; i < field.length(); i++)
    {
        if (!isspace(static_cast<unsigned char>(field[i])))
            return false;
    }
    return true;
}

bool Contact::IsValidNumber(std::string input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (i == 0 && (input[i] == '+'))
            continue;
        if (!isdigit(static_cast<unsigned char>(input[i])))
        {
            std::cout << "Invalid character detected: '" << input[i] << "'. Please enter only numeric characters." << std::endl;
            return false;
        }
    }
    return true;
}

std::string Contact::TruncateField(std::string field)
{
    std::string truncated = field;
    if (field.length() > 10)
    {
        truncated = field.substr(0, 9) + ".";
        return truncated;
    }
    return field;
}


bool Contact::IsValidInput(std::string &input)
{

    if (input.empty() || IsEmpty(input))
    {
        std::cout << "Input cannot be empty." << std::endl;
        return false;
    }
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
    return true;
}

std::string Contact::GetInput(const std::string prompt)
{
    std::string input;
    size_t found;
    std::string markWord = "Phone";

    found = prompt.find(markWord);
    
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cout << "\nEnd of input detected. Exiting the program." << std::endl;
            std::exit(1);
        }
        if (found != std::string::npos && !input.empty() && !IsEmpty(input))
        {
            if (IsValidNumber(input))
                return input;
        }
        else if (IsValidInput(input))
            return input;
    }
    return input;
}

void Contact::DisplayContacts(Contact contacts[8], int index)
{
    if (index == -1)
    {
        std::cout << std::setw(10) << TruncateField("Index") << " | "
                  << std::setw(10) << TruncateField("First Name") << " | "
                  << std::setw(10) << TruncateField("Last Name") << " | "
                  << std::setw(10) << TruncateField("Nickname") << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
        for (int i = 0; i < 8; i++)
        {
            if (contacts[i].firstName.empty())
                break;
            std::cout << std::setw(10) << i
                    << " | " << std::setw(10) << TruncateField(contacts[i].firstName)
                    << " | " << std::setw(10) << TruncateField(contacts[i].lastName)
                    << " | " << std::setw(10) << TruncateField(contacts[i].nickname) << std::endl;
        }
    }
    else if (index >= 0 && index < 8)
    {
        if (contacts[index].firstName.empty())
        {
            std::cout << "No contact found at index " << index << "." << std::endl;
            return;
        }
        std::cout << "First Name: " << contacts[index].firstName << std::endl;
        std::cout << "Last Name: " << contacts[index].lastName << std::endl;
        std::cout << "Nickname: " << contacts[index].nickname << std::endl;
        std::cout << "Phone Number: " << contacts[index].phoneNumber << std::endl;
        std::cout << "Darkest Secret: " << contacts[index].darkestSecret << std::endl;
    }
    else
    {
        std::cout << "Invalid index or contact does not exist." << std::endl;
    }
}

void Contact::FillContact(Contact& contact)
{
    std::string tempFirstName;
    std::string tempLastName;
    std::string tempNickname;
    std::string tempPhoneNumber;
    std::string tempDarkestSecret;

    tempFirstName = contact.GetInput("Enter First Name: ");
    tempLastName = contact.GetInput("Enter Last Name: ");
    tempNickname = contact.GetInput("Enter Nickname: ");
    tempPhoneNumber = contact.GetInput("Enter Phone Number: ");
    tempDarkestSecret = contact.GetInput("Enter Darkest Secret: ");

    if (!tempFirstName.empty() && !tempLastName.empty() && !tempNickname.empty()
        && !tempPhoneNumber.empty() && !tempDarkestSecret.empty())
    {
        contact.firstName = tempFirstName;
        contact.lastName = tempLastName;
        contact.nickname = tempNickname;
        contact.phoneNumber = tempPhoneNumber;
        contact.darkestSecret = tempDarkestSecret;
    }
}
