/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:02:00 by wayden            #+#    #+#             */
/*   Updated: 2025/02/08 04:21:38 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "includes.hpp"

class AForm;

class Bureaucrat
{
public:
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& from);
	~Bureaucrat(void);

	std::string	getName(void) const;
	int			getGrade(void) const;
	void		incrementGrade(void);
	void		decrementGrade(void);

	void		signForm(AForm& form);
	void		executeForm(AForm const & form);
	Bureaucrat &operator=(const Bureaucrat &from);

private:
	const std::string	name;
	int					grade;

	void				isGradeValid(void);

	class GradeTooHighException : public std::exception {
		public:
			const char* what(void) const throw();
	};
	
	class GradeTooLowException : public std::exception {
		public:
			const char* what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& fixed);

#endif