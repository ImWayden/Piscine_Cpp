/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:51:35 by wayden            #+#    #+#             */
/*   Updated: 2024/01/22 16:39:07 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int getRandomNumber(int a, int b) {
    return a + std::rand() % (b - a + 1);
}

int main( void )
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::string prenoms[] = { "Alice", "Bob", "Charlie", "David", "Eva", "Frank", "Grace", "Hank", "Ivy", "Jack", "Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"  };
	int range = getRandomNumber(2,19);
	Zombie* laHorde;
	
	laHorde = zombieHorde(range, "clone");
	for(int i = 0; i < range; ++i)
	{
		std::cout << i << " ";
		laHorde[i].announce();
	}
	delete[] laHorde;
}
