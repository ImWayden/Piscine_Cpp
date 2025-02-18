/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 06:40:10 by wayden            #+#    #+#             */
/*   Updated: 2025/02/15 07:20:02 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "headers/includes.hpp"
 



Base *generate(void)
{
	int nb = std::rand() % 3;
	std::cout << "Generated : ";
	if(!nb)
	{
		std::cout << "A" << std::endl;
		return(new A());
	}

	else if(nb == 1)
	{
		std::cout << "B" << std::endl;
		return(new B());
	}
	else
	{
		std::cout << "C" << std::endl;
		return(new C());
	}
}

void identify(Base* p)
{
	std::cout << "* Identified Type : ";
	if(dynamic_cast<A*>(p))
		std::cout << "A";
	else if(dynamic_cast<B*>(p))
		std::cout << "B";
	else if(dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "Unknown";
	std::cout << std::endl;
}

void identify(Base& p)
{
	std::cout << "& Identified Type : ";
    if(dynamic_cast<A*>(&p))
		std::cout << "A";
	else if(dynamic_cast<B*>(&p))
		std::cout << "B";
	else if(dynamic_cast<C*>(&p))
		std::cout << "C";
	else
		std::cout << "Unknown";
	std::cout << std::endl;
}
