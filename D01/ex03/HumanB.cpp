/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:32:40 by wayden            #+#    #+#             */
/*   Updated: 2024/01/23 13:06:55 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Includes.hpp"

HumanB::HumanB(std::string humanName) : weapon(NULL), name(humanName) {}

HumanB::~HumanB() {}

void HumanB::attack() {
	std::cout << name << " attacks with their ";
	if(weapon != nullptr)
    	std::cout << weapon->getType() << std::endl;
	else
		std::cout << "hands" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;	
}
