/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:51:35 by wayden            #+#    #+#             */
/*   Updated: 2024/01/20 00:29:09 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int getRandomNumber(int a, int b) {
    // Initialiser la graine pour rand() avec le temps actuel
    

    // Générer un nombre aléatoire dans la plage [a, b]
    return a + std::rand() % (b - a + 1);
}

int main( void )
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::string prenoms[] = { "Alice", "Bob", "Charlie", "David", "Eva", "Frank", "Grace", "Hank", "Ivy", "Jack", "Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"  };
	int range = getRandomNumber(0,19);
	Zombie *thenewguy;
	Zombie *laHorde[8];
	
	thenewguy = newZombie("Jerome");
	thenewguy->announce();
	randomChump("Patrick");
	for(int i = 0; i <= range; ++i)
	{
		laHorde[i] = newZombie(prenoms[getRandomNumber(0,19)]);
		laHorde[i]->announce();
		laHorde[i]->announce();
	}
	for(int i = 0; i <= range; ++i)
	{
		delete laHorde[i];
	}
	delete thenewguy;
}
