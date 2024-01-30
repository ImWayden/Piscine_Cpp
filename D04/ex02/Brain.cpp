/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:55:52 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 16:55:09 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Includes.hpp"

Brain::Brain( void ) {std::cout << "Brain " << CONSTRUCTOR << std::endl;}

Brain::Brain(const Brain& from) {std::cout << "Brain Copy " << CONSTRUCTOR << std::endl;
	*this = from;
}

Brain::~Brain( void ) {std::cout << "Brain " << DESTRUCTOR << std::endl;}

Brain& Brain::operator=(const Brain& from) {
	for (size_t i = 0; i < 100; i += 1) {
		this->ideas[i] = from.ideas[i];
	}
    return *this;
}
