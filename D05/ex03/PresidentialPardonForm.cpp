/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:32:35 by wayden            #+#    #+#             */
/*   Updated: 2025/02/08 01:40:22 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", target, false, 25, 5){}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::processContract() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox.";
}


