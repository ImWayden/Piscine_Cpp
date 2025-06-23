/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorManager.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:49:36 by wayden            #+#    #+#             */
/*   Updated: 2025/06/22 21:40:15 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

ErrorManager* ErrorManager::instance = NULL;

ErrorManager::ErrorManager() : error_string(""), error_code(0) {}

ErrorManager::~ErrorManager() {}

ErrorManager* ErrorManager::getInstance()
{
	if (instance == NULL)
		instance = new ErrorManager();
	return instance;
}

void ErrorManager::setError(int code, const std::string& message)
{
	this->error_code = code;
	this->error_string = message;
}

std::string ErrorManager::getErrorMessage() const
{
	return error_string;
}

int ErrorManager::getErrorCode() const
{
	return error_code;
}

void ErrorManager::clear()
{
	error_string = "";
	error_code = 0;
}

void ErrorManager::exitWithError()
{
	std::cerr << "Error (" << error_code << "): " << error_string << std::endl;
	std::exit(error_code);
}


void ErrorManager::exitWithError(int code, const std::string& message)
{
	std::cerr << "Error (" << code << "): " << message << std::endl;
	std::exit(code);
}