/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:59:51 by wayden            #+#    #+#             */
/*   Updated: 2024/01/19 20:00:28 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class.hpp"

Contact::Contact() : notempty(0)
{
	return;
}

Contact::~Contact()
{
	return;	
}

std::string& Contact::getfirstname(){
	return this->Info[FIRSTNAME];
}
void Contact::setfirstname(std::string set){
	this->Info[FIRSTNAME] = set;
}

std::string& Contact::getlastname(){
	return this->Info[LASTNAME];
}
void Contact::setlastname(std::string set){
	this->Info[LASTNAME] = set;
}

std::string& Contact::getnickname(){
	return this->Info[NICKNAME];
}
void Contact::setnickname(std::string set){
	this->Info[NICKNAME] = set;
}

std::string& Contact::getphonenumber(){
	return this->Info[PHONENUMBER];
}
void Contact::setphonenumber(std::string set){
	this->Info[PHONENUMBER] = set;
}

std::string& Contact::getdarkestsecret(){
	return this->Info[DARKESTSECRET];
}
void Contact::setdarkestsecret(std::string set){
	this->Info[DARKESTSECRET] = set;
}

void Contact::setempty(bool var){
	this->notempty = var;
}
bool& Contact::getempty(){
	return this->notempty;
}