/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:00:28 by wayden            #+#    #+#             */
/*   Updated: 2025/02/13 17:14:46 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "includes.hpp"

class Intern
{
public:
	Intern(void);
	Intern(const Intern& intern);

	~Intern(void);
	AForm* makeForm(std::string name, std::string target);
	Intern &operator=(const Intern &from);

	class InvalidContract : public std::exception {
		public:
			const char* what(void) const throw();
	};
private:
	static std::string forms[3];
};



#endif