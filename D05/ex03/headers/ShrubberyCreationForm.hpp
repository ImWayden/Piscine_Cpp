/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:21:30 by wayden            #+#    #+#             */
/*   Updated: 2025/02/08 04:23:27 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "includes.hpp"

class AForm;


class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(std::string target = "undefined");
	~ShrubberyCreationForm();
	
private:
	virtual void processContract() const;
};

#endif