/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:04:24 by wayden            #+#    #+#             */
/*   Updated: 2025/02/13 17:13:48 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Bureaucrat grade too high!";}
const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Bureaucrat grade too low!";}

Bureaucrat::Bureaucrat() : name("undefined"), grade(150){}

Bureaucrat::Bureaucrat(const Bureaucrat& from) : name(from.name), grade(from.grade)
{
	isGradeValid();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	isGradeValid();
}

Bureaucrat::~Bureaucrat(){}
 
//added method
void Bureaucrat::signForm(AForm& form)
{
	try{
		form.beSigned(*this);
		std::cout << *this << " Signed " << form << std::endl;
	} catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << *this << " couldn't sign " << form << " because it's grade is too low" << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form)
{
	try{
		form.execute(*this);
		std::cout << *this << " executed " << form << std::endl;
	} catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << *this << " couldn't execute " << form << " because it's grade is too low" << std::endl;
	}
}

void Bureaucrat::isGradeValid()
{
	if(this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::string	Bureaucrat::getName() const {return this->name;}
int	Bureaucrat::getGrade() const{	return this->grade;}

void	Bureaucrat::incrementGrade()
{
	this->grade--;
	isGradeValid();
}

void	Bureaucrat::decrementGrade()
{
	this->grade++;
	isGradeValid();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& from) {
    if (this != &from) {
        grade = from.getGrade();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}