/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:43:13 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/10/19 08:35:29 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
    private:
        std::string firstName;    
        std::string lastName;    
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        Contact();
        ~Contact();

        void setFirstName(std::string fn);
        void setLastName(std::string ln);
        void setNickName(std::string nm);
        void setPhoneNumber(std::string pn);
        void setDarkestSecret(std::string ds);

        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getDarkestSecret();
};

#endif