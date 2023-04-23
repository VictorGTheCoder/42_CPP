/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victo <victo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:39:59 by victo             #+#    #+#             */
/*   Updated: 2023/04/23 12:17:38 by victo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

# include <string>
# include <iostream>

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

    private:
        std::string firstName_;
        std::string lastName_;
        std::string nickname_;
        std::string phoneNumber_;
        std::string darkestSecret_;
};

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook();
        void addContact();
        void displayContacts() const;
        void searchContact() const;

    private:
        Contact contacts[8];
};



#endif

