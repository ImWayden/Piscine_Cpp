/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:32:35 by wayden            #+#    #+#             */
/*   Updated: 2025/02/08 01:40:22 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, false, 72, 45)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::processContract() const
{
	std::cout << "Bzzz, Bzz, Clang!" << std::endl;
	if(std::rand() % 2)
		std::cout << this->getTarget() << ", has been robotomized successfully!" << std::endl;
	else
		std::cout << this->getTarget() << ", has not been robotomized... what a failure.." << std::endl;
}
