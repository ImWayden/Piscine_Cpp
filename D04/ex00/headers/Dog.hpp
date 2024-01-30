/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 03:49:03 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 04:32:52 by wayden           ###   ########.fr       */
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
protected:

};

#endif