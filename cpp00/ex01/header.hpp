/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victo <victo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:39:59 by victo             #+#    #+#             */
/*   Updated: 2023/05/05 23:15:34 by victo            ###   ########.fr       */
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
        void displayContact(int index) const;
        void searchContact() const;
        int  getSize() const;

    private:
        Contact _contacts[8];
        int     _nbContacts;
};



#endif

