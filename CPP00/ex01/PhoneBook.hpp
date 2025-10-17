/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:41:07 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/10/17 15:34:50 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <cstdlib>

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook
{
private:
    Contact contcats[8];
    int contactCount;
    int oldestIndex;
public:
    PhoneBook();
    ~PhoneBook();
    
    void addContact(Contact c);
    Contact getContact(int index);
    int getContactCount();
    bool isValidIndex(int index);
};

#endif