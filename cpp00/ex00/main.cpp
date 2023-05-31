/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:30:58 by victo             #+#    #+#             */
/*   Updated: 2023/05/31 12:19:17 by vgiordan         ###   ########.fr       */
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
        while (i < argc)
        {
            j = 0;
            while (argv[i][j])
            {
                std::cout << (char) std::toupper(argv[i][j]);
                j++;
            }
            std::cout << " " << std::flush;
            i++;
        }
        std::cout << std::endl;
    }
    return 0;
}
