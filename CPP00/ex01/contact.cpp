/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:34:34 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/10/17 11:53:06 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
    firstName = "";
    lastName = "";
    nickname = "";
    phoneNumber = "";
    darkestSecret = "";
}

Contact::~Contact(){}

void Contact::setFirstName(std::string fn)
{
    firstName = fn;
}

std::string Contact::getFirstName()
{
    return firstName;
}

void Contact::setLastName(std::string ln){
    lastName = ln;
}

std::string Contact::getLastName(){
    return lastName;
}

void Contact::setNickName(std::string nm){
    nickname = nm;
}

std::string Contact::getNickName(){
    return nickname;
}

void Contact::setPhoneNumber(std::string pn){
    phoneNumber = pn;
}

std::string Contact::getPhoneNumber(){
    return phoneNumber;
}

void Contact::setDarkestSecret(std::string ds){
    darkestSecret = ds;
}

std::string Contact::getDarkestSecret(){
    return darkestSecret;
}
