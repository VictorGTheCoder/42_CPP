/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victo <victo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:07:18 by victo             #+#    #+#             */
/*   Updated: 2023/05/01 19:12:13 by victo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void PhoneBook::addContact(int index)
{
    Contact newContact;
	_contacts[index].setContactInfo();
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
	std::cout << "Index      | First Name | Last Name  | Nickname\n";
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << std::setfill(' ') << std::left << i << " | ";
		std::cout << std::setw(10) << std::setfill(' ') << std::left << truncateAndAddDot(_contacts[i].getFirstName()) << " | ";
		std::cout << std::setw(10) << std::setfill(' ') << std::left << truncateAndAddDot(_contacts[i].getLastName()) << " | ";
		std::cout << std::setw(10) << std::setfill(' ') << std::left << truncateAndAddDot(_contacts[i].getNickname()) << std::endl;
	}
}

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook Constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook Destructor called" << std::endl;
	return ;
}