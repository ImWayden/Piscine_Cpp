/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:00:28 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 03:24:52 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Includes.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),\
ScavTrap(name), FragTrap(name){
	std::cout << "Default DiamondTrap " << CONSTRUCTOR << std::endl;
	this->name = name;
	this->HitPoint = FragTrap::HitPoint;
	this->EnergyPoint = ScavTrap::EnergyPoint;
	this->AttackDamage = FragTrap::AttackDamage;
} 

DiamondTrap::~DiamondTrap( void ){
	std::cout << "DiamondTrap " << DESTRUCTOR << std::endl;
}

void DiamondTrap::whoAmI( void ){
	std::cout << "Object Name    : " << this->name << '\n'\
	<< "SubObject Name : " << this->ClapTrap::name << std::endl;
}