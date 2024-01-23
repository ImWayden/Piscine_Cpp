/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:59:03 by wayden            #+#    #+#             */
/*   Updated: 2024/01/23 19:28:59 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include "Includes.hpp"

# define HARL_DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !"
# define HARL_INFO "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !"
# define HARL_WARNING "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
# define HARL_ERROR "This is unacceptable ! I want to speak to the manager now."

class Harl{

public:
	Harl();
	~Harl();
	void complain(std::string level);	
private:
	bool check(std::string input);
	int	hash(const std::string& str);
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};

#endif