/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victo <victo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:30:58 by victo             #+#    #+#             */
/*   Updated: 2023/04/23 12:02:12 by victo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char const *argv[])
{
    int i;
    int j;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    }
    else
    {
        i = 1;
        j = 0;
        while (i < argc)
        {
            while (argv[i][j])
            {
                std::cout << (char) std::toupper(argv[i][j]);
                j++;
            }
            std::cout << "\n";
            i++;
        }
    }
    return 0;
}
