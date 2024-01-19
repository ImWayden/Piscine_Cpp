/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:51:43 by wayden            #+#    #+#             */
/*   Updated: 2024/01/19 18:52:36 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdio.h>
#include <cctype>
namespace Megaphone
{
	void noise(void)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	int scream(const char *str)
	{
		std::string input = str;

		for (char& c : input) {
       	 	c = std::toupper(c);
    	}
		std::cout << input;
		return 1;
	}
} // namespace megaphone

int main(int argc, char **argv)
{
	int i = 0;
	int isvalid = 0;
	
	if(argc < 2)
		return (Megaphone::noise(),0);
	while(++i < argc)
		Megaphone::scream(argv[i]);
	std::cout << std::endl;
	return 0;
}