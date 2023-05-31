/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:38:29 by victo             #+#    #+#             */
/*   Updated: 2023/05/31 18:02:50 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setContactInfo()
{
    _firstName = "";
    _lastName = "";
    _nickname = "";
    _phoneNumber = "";
    _darkestSecret = "";
    while (_firstName.empty() && !std::cin.eof())
    {
        std::cout << "First Name: ";
        std::getline(std::cin, _firstName);
    }

    while (_lastName.empty() && !std::cin.eof())
    {
        std::cout << "Last Name: ";
        std::getline(std::cin, _lastName);
    }
    
    while (_nickname.empty() && !std::cin.eof())
    {    
        std::cout << "Nickname: ";
        std::getline(std::cin, _nickname);   
    }

    while (_phoneNumber.empty() && !std::cin.eof())
    {
        std::cout << "Phone Number: ";
        std::getline(std::cin, _phoneNumber);
    }
    
    while (_darkestSecret.empty() && !std::cin.eof())
    {
        std::cout << "Darkest Secret: ";
        std::getline(std::cin, _darkestSecret);
    }
}

std::string Contact::getFirstName() const
{
    return   this->_firstName;  
}

std::string Contact::getLastName() const
{
    return this->_lastName;
}

std::string Contact::getNickname() const
{
    return this->_nickname;
}

std::string Contact::getPhoneNumber() const
{
    return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return this->_darkestSecret;
}

Contact::Contact(void)
{
	//std::cout << "Contact Constructor called" << std::endl;

	return ;
}

Contact::~Contact(void)
{
	//std::cout << "Contact Destructor called" << std::endl;
	return ;
}
