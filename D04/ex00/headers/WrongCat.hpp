/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 03:49:38 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 04:41:51 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "Includes.hpp"

class WrongCat : public WrongAnimal{

public:
	WrongCat( void );
	WrongCat(WrongCat& from);
	~WrongCat( void );

	void makeSound( void ) const;
protected:

};

#endif