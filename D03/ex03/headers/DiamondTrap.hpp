/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:00:51 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 02:24:44 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "Includes.hpp"

class DiamondTrap: public ScavTrap, public FragTrap{
public:
	DiamondTrap(std::string name);
	~DiamondTrap( void );
	
	using ScavTrap::attack;
	void whoAmI( void );
private:
	std::string name;
};

#endif