/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:47:14 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 03:06:07 by wayden           ###   ########.fr       */
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
	std::stringstream ss;
	ss << GATEKEEP << std::endl;
	checkEnergyandLife(ss.str(), "ScavTrap");
}

void ScavTrap::attack(const std::string& target){
	std::stringstream ss;
	ss << " attacks " << target\
	<< ", causing " << this->AttackDamage << " points of damage! " << std::endl;
	checkEnergyandLife(ss.str(), "ScavTrap");
}