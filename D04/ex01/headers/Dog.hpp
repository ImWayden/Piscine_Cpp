/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 03:49:03 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 16:37:48 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Includes.hpp"

class Dog : public Animal{

public:
	Dog( void );
	Dog(Dog& from);
	~Dog( void );

	void makeSound( void ) const override;

	Dog &operator=(const Dog &from);
private:
	Brain* ideas;
};

#endif