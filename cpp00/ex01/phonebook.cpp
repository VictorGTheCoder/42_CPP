/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victo <victo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:07:18 by victo             #+#    #+#             */
/*   Updated: 2023/04/23 17:27:37 by victo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void PhoneBook::addContact()
{
    Contact newContact;
    newContact.setContactInfo();
    contacts_.push_back(newContact);
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