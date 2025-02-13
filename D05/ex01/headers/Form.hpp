/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:12:17 by wayden            #+#    #+#             */
/*   Updated: 2025/02/13 17:12:37 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "includes.hpp"

class Bureaucrat;

class Form
{
public:
	Form(void);
	Form(std::string name, bool isSigned, int gradeToSign, int gradeToExec);
	Form(const Form& from);
	~Form(void);
	
	void beSigned(Bureaucrat& bureaucrat); 
	
	std::string getName(void) const;
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
	
	Form &operator=(const Form &from);
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExec;

	void isGradeValid();
	

};

std::ostream& operator<<(std::ostream& os, const Form& fixed);

#endif