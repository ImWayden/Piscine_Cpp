/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorManager.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:37:52 by wayden            #+#    #+#             */
/*   Updated: 2025/06/27 16:07:32 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORMANAGER_HPP
#define ERRORMANAGER_HPP

#include "includes.hpp"

class ErrorManager
{
public:
	static ErrorManager* getInstance();

	void setError(int code, const std::string& message);
	std::string getErrorMessage() const;
	int getErrorCode() const;
	void clear();

	// Quitte le programme avec un message d'erreur
	void exitWithError();
	void exitWithError(int code, const std::string& message);

private:
	ErrorManager();
	~ErrorManager();

	ErrorManager(const ErrorManager&);
	ErrorManager& operator=(const ErrorManager&);

	std::string error_string;
	int error_code;

	static ErrorManager* instance;
};

template <typename Container>
void printContent(std::string str,Container& v_ints)
{
	std::cout << str;
	for(size_t i = 0; i < v_ints.size(); i++)
		std::cout << " " << v_ints[i];
	std::cout << std::endl;
}

#endif // ERRORMANAGER_HPP