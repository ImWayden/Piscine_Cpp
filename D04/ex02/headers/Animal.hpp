/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 03:49:57 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 17:07:50 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include "Includes.hpp"
class Animal{

public:
	Animal( void );
	Animal(Animal& from);
	virtual ~Animal( void );
	
	std::string getType( void ) const;
	virtual void makeSound( void ) const = 0;

	Animal &operator=(const Animal &from);
protected:
	std::string type;
};



#endif