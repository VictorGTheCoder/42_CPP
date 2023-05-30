/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:14:53 by vgiordan          #+#    #+#             */
/*   Updated: 2023/05/23 10:24:07 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

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