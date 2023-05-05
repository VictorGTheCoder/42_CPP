/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victo <victo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:11:26 by victo             #+#    #+#             */
/*   Updated: 2023/05/05 23:44:12 by victo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main(void)
{
    PhoneBook phonebook;
    std::string input;
    int index = 0;

    while (42)
    {
        std::cout << "PhoneBook > ";
        std::getline (std::cin, input);
        if (input == "EXIT")
            break ;
        else if(input == "ADD")
        {
            phonebook.addContact(index % 8);
            index++;
        }
        else if (input == "SEARCH" || input == "s")
        {
            phonebook.displayContacts();
            std::cout << "Enter Index > ";
            std::getline (std::cin, input);
            if (!input.empty() && std::isdigit(input[0]))
            {
                int i = input[0] - '0';
                if (i >= 0 && i < phonebook.getSize() && input.length() == 1)
                {
                    phonebook.displayContact(i);
                }
                else
                    std::cout << "invalid input" << std::endl;
            }
            else
                std::cout << "Please enter a valid digit" << std::endl;
            
        }
        else
            std::cout << "Please enter: ADD, SEARCH or EXIT" << std::endl;
    }
    return 0;
}
