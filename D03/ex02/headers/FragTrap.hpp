/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:25:10 by wayden            #+#    #+#             */
/*   Updated: 2024/01/29 17:31:38 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "Includes.hpp"

class FragTrap : public ClapTrap{
public:
	FragTrap(std::string name);
	~FragTrap( void );
	
	void highFivesGuys(void);
private:
};


#endif