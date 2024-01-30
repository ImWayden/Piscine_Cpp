/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 04:37:54 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 04:40:56 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include "Includes.hpp"
class WrongAnimal{

public:
	WrongAnimal( void );
	WrongAnimal(WrongAnimal& from);
	virtual ~WrongAnimal( void );

	std::string getType( void ) const;
	void makeSound( void ) const;
protected:
	std::string type;
};



#endif