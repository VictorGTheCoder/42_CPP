/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victo <victo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:38:29 by victo             #+#    #+#             */
/*   Updated: 2023/04/23 12:15:59 by victo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void Contact::setContactInfo()
{
    std::cout << "First Name: ";
    std::getline(std::cin, firstName_);

    std::cout << "Last Name: ";
    std::getline(std::cin, lastName_);

    std::cout << "Nickname: ";
    std::getline(std::cin, nickname_);

    std::cout << "Phone Number: ";
    std::getline(std::cin, phoneNumber_);

    std::cout << "Darkest Secret: ";
    std::getline(std::cin, darkestSecret_);
}

Contact::Contact(void)
{
	std::cout << "Contact Constructor called" << std::endl;

	return ;
}

Contact::~Contact(void)
{
	std::cout << "Contact Destructor called" << std::endl;
	return ;
}
