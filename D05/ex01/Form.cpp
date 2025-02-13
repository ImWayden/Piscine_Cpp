/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:21:07 by wayden            #+#    #+#             */
/*   Updated: 2025/02/13 17:12:46 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

const char* Form::GradeTooHighException::what() const throw() { return "Contract grade too high!";}
const char* Form::GradeTooLowException::what() const throw() { return "Contract grade too low!";}

Form::Form() : name("undefined"), isSigned(false), gradeToSign(1), gradeToExec(1){}

Form::Form(std::string name, bool isSigned, int gradeToSign, int gradeToExec) : name(name), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExec(gradeToExec){
	isGradeValid();
}

Form::Form(const Form& from) : name(from.getName()), isSigned(from.getIsSigned()), gradeToSign(from.getGradeToSign()), gradeToExec(from.getGradeToExec()){
	isGradeValid();
}

Form::~Form() {}


void Form::beSigned(Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() <= this->gradeToSign)
		this->isSigned = true;
	else
		throw Form::GradeTooLowException();
}


void Form::isGradeValid()
{
	if(this->gradeToSign < 1 || this->gradeToExec < 1)
		throw Form::GradeTooHighException();
	else if(this->gradeToSign > 150 || this->gradeToExec > 150)
		throw Form::GradeTooLowException();
}

std::string Form::getName() const {return this->name;}
bool Form::getIsSigned() const { return this->isSigned;}
int Form::getGradeToSign() const { return this->gradeToSign;}
int Form::getGradeToExec() const { return this->gradeToExec;}

Form& Form::operator=(const Form &from)
{
	if(this != &from)
		isSigned = from.getIsSigned();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& fixed){
	os << fixed.getName() << ", contract grade to sign : " << fixed.getGradeToSign() \
	<< ", contract grade to exec : " << fixed.getGradeToExec() << " is contract signed : " << fixed.getIsSigned();
	return os;
}