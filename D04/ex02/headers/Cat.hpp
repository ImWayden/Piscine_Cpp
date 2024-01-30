/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 03:49:38 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 16:25:57 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Includes.hpp"

class Cat : public Animal{

public:
	Cat( void );
	Cat(Cat& from);
	~Cat( void );

	void makeSound( void ) const override;

	Cat &operator=(const Cat &from);
private:
	Brain *ideas;
};

#endif