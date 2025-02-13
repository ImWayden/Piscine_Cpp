/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:45:01 by wayden            #+#    #+#             */
/*   Updated: 2025/02/08 04:23:20 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDON_HPP
# include "includes.hpp"

class AForm;


class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(std::string target = "undefined");
	~PresidentialPardonForm();
private:
	virtual void processContract() const;
};

#endif