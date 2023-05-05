/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victo <victo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:38:29 by victo             #+#    #+#             */
/*   Updated: 2023/05/05 23:23:13 by victo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void Contact::setContactInfo()
{
    std::cout << "First Name: ";
    std::getline(std::cin, _firstName);

    std::cout << "Last Name: ";
    std::getline(std::cin, _lastName);

    std::cout << "Nickname: ";
    std::getline(std::cin, _nickname);

    std::cout << "Phone Number: ";
    std::getline(std::cin, _phoneNumber);

    std::cout << "Darkest Secret: ";
    std::getline(std::cin, _darkestSecret);
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
