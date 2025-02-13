/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:32:35 by wayden            #+#    #+#             */
/*   Updated: 2025/02/08 04:26:57 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, false, 145, 137){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::processContract() const
{
	std::string filename = this->getTarget() + "_shrubbery";

	std::ofstream file(filename.c_str());
	if(!file)
		return;
	file << "\n\
		&&& &&  & &&\n\
	&& &\\/&\\|& ()|/ @, &&\n\
	&\\/(/&/&||/& /_/)_&/_&\n\
 &() &\\/&|()|/&\\/ '%\" & ()\n\
&_\\_&&_\\ |& |&&/&__%_/_& &&\n\
&&   && & &| &| /& & % ()& /&&\n\
()&_---()&\\\\&\\|&&-&&--%---()~\n\
	&&     \\\\\n\
			|||\n\
			|||\n\
			|||\n\
			|||\n\
	  , -=-~  .-^- _\n"
	<< std::endl;
}


