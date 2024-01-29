/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:47:14 by wayden            #+#    #+#             */
/*   Updated: 2024/01/29 17:18:00 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Includes.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "Default ScavTrap " << CONSTRUCTOR << std::endl;
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
}

ScavTrap::~ScavTrap( void ){
	std::cout << "ScavTrap " << DESTRUCTOR << std::endl;
}

void ScavTrap::guardGate( void ){
	std::cout << "ScavTrap " << this->name << GATEKEEP << std::endl;
}

void ScavTrap::attack(const std::string& target){
	std::cout << "ScavTrap " << this->name;
	if(this->HitPoint && this->EnergyPoint)
	{
		std::cout << " attacks " << target\
		<< ", causing " << this->AttackDamage << " points of damage! " << std::endl;
		this->EnergyPoint -= 1;
	}
	else if(!this->HitPoint)
		std::cout << OUTHP << ATTACK << std::endl; 
	else
		std::cout << OUTENERGY << ATTACK << std::endl; 
}