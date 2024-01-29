/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:59:26 by wayden            #+#    #+#             */
/*   Updated: 2024/01/29 17:07:22 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Includes.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), HitPoint(10), EnergyPoint(10), AttackDamage(0){
	std::cout << "Default ClapTrap" << CONSTRUCTOR << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& from) : name(from.name), HitPoint(from.HitPoint),\
EnergyPoint(from.EnergyPoint), AttackDamage(from.AttackDamage){
	std::cout << "Copy Claptrap" << CONSTRUCTOR << std::endl;
}


ClapTrap::~ClapTrap( void ){
	std::cout << "ClapTrap " << DESTRUCTOR << std::endl;
}

void ClapTrap::attack(const std::string& target){
	std::cout << "ClapTrap " << this->name;
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

void ClapTrap::takeDamage(unsigned int amount){
	int after = this->HitPoint - amount;
	this->HitPoint = clamp(after,0,this->HitPoint);
	std::cout << "ClapTrap " << this->name << " took "\
	<< amount << " points of damage! " << std::endl;
	std::cout << "HP Left : " << this->HitPoint << std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount){
	std::cout << "ClapTrap " << this->name;
	int after = this->HitPoint + amount;
	if(this->HitPoint && this->EnergyPoint)
	{
		this->HitPoint = clamp(after,this->HitPoint,after);
		std::cout << "is being repaired!"\
		<< "\nHe regained " << amount << " HitPoints!" << std::endl;
		std::cout << "HP Left : " << this->HitPoint << std::endl;
		this->EnergyPoint -= 1;
	}
	else if(!this->HitPoint)
		std::cout << OUTHP << REPAIR << std::endl; 
	else
		std::cout << OUTENERGY << REPAIR << std::endl; 
}

ClapTrap& ClapTrap::operator=(const ClapTrap& from){
	if (this != &from){
		this->name = from.name;
		this->AttackDamage = from.AttackDamage;
		this->EnergyPoint = from.EnergyPoint;
		this->HitPoint = from.HitPoint;
	}
	return(*this);
}

std::ostream& ClapTrap::print(std::ostream& os) const
{
	os << "Name        : " << this->name << '\n'\
	<< "HitPoint    : " << this->HitPoint << '\n'\
	<< "EnergyPoint : " << this->EnergyPoint << '\n'\
	<< "AttackDmg   : " << this->AttackDamage << std::endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, const ClapTrap& Bot){
	Bot.print(os);
	return os;
}