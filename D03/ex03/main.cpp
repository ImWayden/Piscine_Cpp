/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:59:29 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 03:22:26 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Includes.hpp"

int main( void )
{
	std::cout << "---------------BOT 1-------------------" << std::endl;
	ClapTrap Bot3("Clappy");
	Bot3.takeDamage(1);
	std::cout << Bot3 << std::endl;
	for(int i = 0; i < 11; i++)
		Bot3.attack("no one");
	std::cout << Bot3 << std::endl;
	Bot3.takeDamage(10000000);
	Bot3.attack("no one");
	Bot3.beRepaired(1);
	std::cout << Bot3 << std::endl;
	std::cout << "---------------BOT 4-------------------" << std::endl;
	ScavTrap Bot4("Patrick");
	std::cout << Bot4 << std::endl;
	Bot4.ClapTrap::attack("no one");
	Bot4.attack("a shy ghost");
	Bot4.guardGate();
	Bot4.takeDamage(100);
	Bot4.beRepaired(1);
	std::cout << Bot4 << std::endl;
	std::cout << "---------------BOT 5-------------------" << std::endl;
	FragTrap Bot5("Jean");
	std::cout << Bot5 << std::endl;
	Bot5.ClapTrap::attack("no one");
	Bot5.attack("a shy ghost");
	Bot5.highFivesGuys();
	Bot5.takeDamage(100);
	Bot5.beRepaired(1);
	std::cout << Bot5 << std::endl;
	std::cout << "---------------BOT 6-------------------" << std::endl;
	DiamondTrap Bot6("TopG");
	std::cout << Bot6 << std::endl;
	Bot6.ClapTrap::attack("no one");
	Bot6.attack("a shy ghost");
	Bot6.highFivesGuys();
	Bot6.whoAmI();
	Bot6.guardGate();
	std::cout << Bot6 << std::endl;
	Bot6.takeDamage(100);
	Bot6.beRepaired(1);
	std::cout << Bot6 << std::endl;
}