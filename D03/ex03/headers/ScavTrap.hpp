/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:47:14 by wayden            #+#    #+#             */
/*   Updated: 2024/01/30 02:18:16 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "Includes.hpp"

class ScavTrap : virtual public ClapTrap {

public:
	ScavTrap(std::string name);
	~ScavTrap( void );

	void attack(const std::string& target);
	void guardGate();
private:
	
};



#endif