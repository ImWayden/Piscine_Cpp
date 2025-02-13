/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:21:07 by wayden            #+#    #+#             */
/*   Updated: 2025/02/08 13:11:22 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

const char* AForm::GradeTooHighException::what() const throw(){ return "Contract grade too high!";}
const char* AForm::GradeTooLowException::what() const throw(){ return "Contract grade too low!";}

AForm::AForm() : name("undefined"), target("undefined"), isSigned(false), gradeToSign(1), gradeToExec(1){}

AForm::AForm(std::string name, std::string target, bool isSigned, int gradeToSign, int gradeToExec) : name(name), target(target), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExec(gradeToExec){
	isGradeValid();
}

AForm::AForm(const AForm& from) : name(from.getName()), target(from.getTarget()), isSigned(from.getIsSigned()), gradeToSign(from.getGradeToSign()), gradeToExec(from.getGradeToExec()){
	isGradeValid();
}

AForm::~AForm() {}


void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() <= this->gradeToSign)
		this->isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
	if(executor.getGrade() <= this->gradeToExec)
		this->processContract();
	else
		throw AForm::GradeTooLowException();
}

void AForm::isGradeValid()
{
	if(this->gradeToSign < 1 || this->gradeToExec < 1)
		throw AForm::GradeTooHighException();
	else if(this->gradeToSign > 150 || this->gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

std::string AForm::getName() const {return this->name;}
std::string AForm::getTarget() const { return this->target;}
bool AForm::getIsSigned() const { return this->isSigned;}
int AForm::getGradeToSign() const { return this->gradeToSign;}
int AForm::getGradeToExec() const { return this->gradeToExec;}

AForm& AForm::operator=(const AForm &from)
{
	if(this != &from)
		isSigned = from.getIsSigned();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& fixed){
	os << fixed.getName() << " Target :" << fixed.getTarget() << ", contract grade to sign : " << fixed.getGradeToSign() \
	<< ", contract grade to exec : " << fixed.getGradeToExec() << " is contract signed : " << fixed.getIsSigned();
	return os;
}