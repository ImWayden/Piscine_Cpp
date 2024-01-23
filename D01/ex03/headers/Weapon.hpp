/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:10:41 by wayden            #+#    #+#             */
/*   Updated: 2024/01/22 17:47:34 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include "Includes.hpp"

class Weapon{

public:
	Weapon(std::string string);
	~Weapon();
	const std::string &getType() const;
	void setType(const std::string& value);
private:
	std::string type;
};
#endif