/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:59:03 by wayden            #+#    #+#             */
/*   Updated: 2024/01/23 18:53:40 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include "Includes.hpp"


class Harl{

public:
	Harl();
	~Harl();
	void complain(std::string level);	
private:
	int	hash(const std::string& str);
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};
#endif