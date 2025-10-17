/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:46:29 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/10/17 12:56:33 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    contactCount = 0;
    oldestIndex = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact(Contact c)
{
    if (contactCount < 8)
    {
        contcats[contactCount] = c;
        contactCount++;
    }
    else
    {
        contcats[oldestIndex] = c;
        oldestIndex = (oldestIndex + 1) % 8;
    }
}

Contact PhoneBook::getContact(int index)
{
    return contcats[index];
}

int PhoneBook::getContactCount()
{
    return contactCount;
}

bool PhoneBook::isValidIndex(int index)
{
    if (index >= 0 && index < contactCount)
        return true;
    return false;
}