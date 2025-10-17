/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:54:13 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/10/17 16:27:18 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

// display table

void displayTable(PhoneBook &pb)
{
    std::cout << "|";
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
    
    for (int i = 0; i < pb.getContactCount(); i++)
    {
        Contact c = pb.getContact(i);
        std::string firstName = c.getFirstName();
        std::string lastName = c.getLastName();
        std::string nickName = c.getNickName();

        // truncate if longer than 10 carchters
        if (firstName.length() > 10)
            firstName = firstName.substr(0, 9) + ".";
        else if (lastName.length() > 10)
            lastName = lastName.substr(0, 9) + ".";
        else if (nickName.length() > 10)
            nickName = nickName.substr(0, 9) + ".";

        std::cout << "|";
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << firstName << "|";
        std::cout << std::setw(10) << lastName << "|";
        std::cout << std::setw(10) << nickName << "|" << std::endl;
    }
}

void addContactPrompt(PhoneBook &pb)
{
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phonenumber;
    std::string darkestsecret;

    std::cout << "Enter First Name : ";
    if (!std::getline(std::cin, firstname) || firstname.empty())
    {
        std::cout << "Error : First Name cannot be empty !" << std::endl;
        return ;
    }

    std::cout << "Enter Last Name : ";
    if (!std::getline(std::cin, lastname) || lastname.empty())
    {
        std::cout << "Error : Last Name cannot be empty !" << std::endl;
        return ;
    }

    std::cout << "Enter Nickname : ";
    if (!std::getline(std::cin, nickname) || nickname.empty())
    {
        std::cout << "Error : Nickname cannot be empty !" << std::endl;
        return ;
    }

    std::cout << "Enter Phone Number : ";
    if (!std::getline(std::cin, phonenumber) || phonenumber.empty())
    {
        std::cout << "Error : Phone Number cannot be empty !" << std::endl;
        return ;
    }
    
    std::cout << "Enter Darkest Secret : ";
    if (!std::getline(std::cin, darkestsecret) || darkestsecret.empty())
    {
        std::cout << "Error : Darkest Secret cannot be empty !" << std::endl;
        return ;
    }

    Contact newContact;
    newContact.setFirstName(firstname);
    newContact.setLastName(lastname);
    newContact.setNickName(nickname);
    newContact.setPhoneNumber(phonenumber);
    newContact.setDarkestSecret(darkestsecret);

    pb.addContact(newContact);
    std::cout << "Contact added successfully !" << std::endl;
}

void searchContact(PhoneBook &pb)
{
    if (pb.getContactCount() == 0)
    {
        std::cout << "No contact to display !!" << std::endl;
        return ;
    }
    
    displayTable(pb);

    std::string indexStr;
    std::cout << "Enter Contact Index : ";
    if (!std::getline(std::cin, indexStr))
        return ;
    
    int index = std::atoi(indexStr.c_str());
    
    if (!pb.isValidIndex(index))
    {
        std::cout << "Error : Invalid Index !" << std::endl;
        return ;
    }

    Contact c = pb.getContact(index);
    std::cout << "First Name : " << c.getFirstName() << std::endl;
    std::cout << "Last Name : " << c.getLastName() << std::endl;
    std::cout << "Nickname : " << c.getNickName() << std::endl;
    std::cout << "Phone Number : " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret : " << c.getDarkestSecret() << std::endl;
}

int main()
{
    PhoneBook pb;
    std::string command;
    
    while (1)
    {
        std::cout << "Enter command (ADD, SEARCH OR EXIT): ";
        if (!std::getline(std::cin, command))
            break ;
        if (command == "ADD")
            addContactPrompt(pb);
        else if (command == "SEARCH")
            searchContact(pb);
        else if (command == "EXIT")
            break ;
    }
    return 0;
}