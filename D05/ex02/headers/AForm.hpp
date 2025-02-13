/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:12:17 by wayden            #+#    #+#             */
/*   Updated: 2025/02/08 04:21:17 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "includes.hpp"

class Bureaucrat;

class AForm
{
public:
	AForm(void);
	AForm(std::string name, std::string target, bool isSigned, int gradeToSign, int gradeToExec);
	AForm(const AForm& from);
	virtual ~AForm(void);
	
	void beSigned(Bureaucrat& bureaucrat);
	void execute(Bureaucrat const & executor) const;
	
	std::string getName(void) const;
	std::string getTarget(void) const;
	bool getIsSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExec(void) const;

	class GradeTooHighException : public std::exception {
		public:
			const char* what(void) const throw();
	};
	
	class GradeTooLowException : public std::exception {
		public:
			const char* what(void) const throw();
	};
	
	AForm &operator=(const AForm &from);
private:
	const std::string name;
	const std::string target;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExec;

	void isGradeValid();
	virtual void processContract() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& fixed);

#endif