/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:03:07 by wayden            #+#    #+#             */
/*   Updated: 2024/01/29 13:01:04 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap{
public:
	//ClapTrap( void );
	ClapTrap(std::string name);
	ClapTrap(ClapTrap& from);
	
	~ClapTrap( void );
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::ostream& print(std::ostream& os) const;
	ClapTrap& operator=(const ClapTrap& autre);
private:
	std::string name;
	int HitPoint;
	int EnergyPoint;
	int AttackDamage;
};

std::ostream& operator<<(std::ostream& os, const ClapTrap& fixed);

#endif