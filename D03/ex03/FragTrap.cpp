/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:30:01 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 03:02:12 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Includes.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name){
	std::cout << "Default FragTrap " << CONSTRUCTOR << std::endl;
	this->HitPoint = 100;
	this->EnergyPoint = 100;
	this->AttackDamage = 30;
}

FragTrap::~FragTrap( void ){
	std::cout << "FragTrap " << DESTRUCTOR << std::endl;
}

void	FragTrap::highFivesGuys(void){
	std::stringstream ss;
	ss << HIGHFIVE << std::endl;
	checkEnergyandLife(ss.str(), "FragTrap");
}