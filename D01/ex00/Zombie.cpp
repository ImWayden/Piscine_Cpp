/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:51:30 by wayden            #+#    #+#             */
/*   Updated: 2024/01/20 00:10:59 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;	
	return;
}

Zombie::~Zombie()
{
	int deathcause = getRandomNumber(1, 100);
	
	if(deathcause % 10 == 1)
		std::cout << this->name << " est retourné a la poussière." << std::endl;
	else if(deathcause % 10 == 2)
		std::cout << this->name << " avais la flemme de vivre plus longtemps." << std::endl;
	else if(deathcause % 10 == 3)
		std::cout << this->name << " mange les pissenlits par la racine." << std::endl;
	else if(deathcause % 10 == 4)
		std::cout << this->name << " a préféré retourner dormir." << std::endl;
	else if(deathcause % 10 == 5)
		std::cout << this->name << " ne savait donc pas voler..." << std::endl;
	else if(deathcause % 10 == 6)
		std::cout << this->name << " a explosé." << std::endl;
	else if(deathcause % 10 == 7)
		std::cout << this->name << " n'a jamais vraiment été vivant, dans le fond ca n'a jamais été que quelques lignes de code" << std::endl;
	else if(deathcause % 10 == 8)
		std::cout << this->name << " a marché sur un lego" << std::endl;
	else if(deathcause % 10 == 9)
		std::cout << this->name << " a manger trop épicé" << std::endl;
	else
		std::cout << this->name << " n'avait plus d'inspi" << std::endl;
	return;		
}

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
