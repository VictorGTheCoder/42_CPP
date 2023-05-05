/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victo <victo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:07:18 by victo             #+#    #+#             */
/*   Updated: 2023/05/05 23:33:20 by victo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void PhoneBook::addContact(int index)
{
    Contact newContact;
	_contacts[index].setContactInfo();
	if (_nbContacts < 8)
		_nbContacts++;
}

int PhoneBook::getSize() const
{
	return (this->_nbContacts);
}

std::string truncateAndAddDot(const std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

void PhoneBook::displayContacts() const
{
	std::cout << "     Index | First Name |  Last Name | Nickname\n";
	for (int i = 0; i < this->getSize(); i++)
	{
		std::cout << std::setw(10) << std::setfill(' ') << std::right << i << " | ";
		std::cout << std::setw(10) << std::setfill(' ') << std::right << truncateAndAddDot(_contacts[i].getFirstName()) << " | ";
		std::cout << std::setw(10) << std::setfill(' ') << std::right << truncateAndAddDot(_contacts[i].getLastName()) << " | ";
		std::cout << std::setw(10) << std::setfill(' ') << std::right << truncateAndAddDot(_contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::displayContact(int index) const
{
	std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

PhoneBook::PhoneBook(void)
{
	//std::cout << "PhoneBook Constructor called" << std::endl;
	this->_nbContacts = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	//std::cout << "PhoneBook Destructor called" << std::endl;
	return ;
}
