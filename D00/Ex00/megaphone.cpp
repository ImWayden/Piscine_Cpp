/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:51:43 by wayden            #+#    #+#             */
/*   Updated: 2024/01/19 14:15:23 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdio.h>
namespace Megaphone
{
	void noise(void)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	int scream(const char *str)
	{
		int i;
		int isvalid;

		i = -1;
		isvalid = 0;
		while(str[++i])
		{
			if(str[i] > 32 && str[i] < 127)
				isvalid++;
		}
		i = -1;
		if(!isvalid)
			return 0;
		else
		{
			while(str[++i])
			{
				if(str[i] >= 'a' && str[i] <= 'z')
					std::cout << static_cast<char>(str[i] - 32);
				else
					std::cout << static_cast<char>(str[i]);
			}
		}
		return 1;
	}
} // namespace megaphone

int main(int argc, char **argv)
{
	int i = 0;
	int isvalid = 0;
	
	while(++i < argc){
		if(Megaphone::scream(argv[i]))
			isvalid++;
	}	
	if(!isvalid)
		Megaphone::noise();
	else
		std::cout << std::endl;
	return 0;
}