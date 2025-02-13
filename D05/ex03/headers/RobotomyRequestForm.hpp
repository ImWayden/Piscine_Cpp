/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:40:52 by wayden            #+#    #+#             */
/*   Updated: 2025/02/08 04:23:24 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "includes.hpp"

class AForm;


class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(std::string target = "undefined");
	~RobotomyRequestForm();
	
private:
	virtual void processContract() const;
};


#endif