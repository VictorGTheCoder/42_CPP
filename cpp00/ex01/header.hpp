/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victo <victo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:39:59 by victo             #+#    #+#             */
/*   Updated: 2023/05/01 19:16:48 by victo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

# include <string>
# include <iostream>
#include <iomanip>

class Contact
{
    public:
        Contact(void);
        ~Contact(void);
        void setContactInfo();
        void displayContact() const;

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;

    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
};

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook();
        void addContact(int index);
        void displayContacts() const;
        void searchContact() const;

    private:
        Contact _contacts[8];
};



#endif

