/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:59:29 by wayden            #+#    #+#             */
/*   Updated: 2024/01/29 13:36:28 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Includes.hpp"



int main( void )
{
	ClapTrap Bot("Clappy");
	ClapTrap Bot2(Bot);
	ClapTrap Bot3("Bobby");
	
	std::cout << Bot << std::endl;
	std::cout << Bot2 << std::endl;
	std::cout << Bot3 << std::endl;
	
	std::cout << "---------------BOT 1-------------------" << std::endl;
	Bot.takeDamage(100);
	Bot.attack("a fucking monster");
	std::cout << Bot << std::endl;
	std::cout << "---------------BOT 2-------------------" << std::endl;
	Bot2.beRepaired(100);
	std::cout << Bot2 << std::endl;
	Bot2.takeDamage(1000);
	Bot2.beRepaired(100);
	std::cout << Bot2 << std::endl;
	std::cout << "---------------BOT 3-------------------" << std::endl;
	Bot3.takeDamage(1);
	std::cout << Bot3 << std::endl;
	Bot3.attack("no one");
	Bot3.attack("no one");
	Bot3.attack("no one");
	Bot3.attack("no one");
	Bot3.attack("no one");
	Bot3.attack("no one");
	Bot3.attack("no one");
	Bot3.attack("no one");
	Bot3.attack("no one");
	Bot3.attack("no one");
	Bot3.attack("no one");
	Bot3.attack("no one");
	Bot3.attack("no one");
	Bot3.takeDamage(10000000);
	Bot3.attack("no one");
	Bot3.beRepaired(1);
	std::cout << Bot3 << std::endl;
}