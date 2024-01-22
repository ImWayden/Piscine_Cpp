/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:51:39 by wayden            #+#    #+#             */
/*   Updated: 2024/01/19 23:47:08 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstring>
#include <limits>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Zombie{

public:
	Zombie( std::string name);
	~Zombie( void );
	void announce( void );
private:
	std::string name;
	
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );
int getRandomNumber(int a, int b);