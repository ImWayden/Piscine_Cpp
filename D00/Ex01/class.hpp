/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:36:31 by wayden            #+#    #+#             */
/*   Updated: 2024/01/22 17:02:16 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
# define CLASS_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <limits>
#include <iostream>
#include <iomanip>
#include <string>

enum e_info {
	FIRSTNAME,
	LASTNAME,
	NICKNAME,
	PHONENUMBER,
	DARKESTSECRET
};

class Contact {
public:
	Contact( void );
	~Contact( void );

	void	setfirstname(std::string set);
	void	setlastname(std::string set);
	void	setnickname(std::string set);
	void	setphonenumber(std::string set);
	void	setdarkestsecret(std::string set);
	void	setempty(bool var);
	std::string& getfirstname();
	std::string& getlastname();
	std::string& getnickname();
	std::string& getphonenumber();
	std::string& getdarkestsecret();
	bool& getempty();
private:
	std::string Info[5];
	bool  notempty;
};


class PhoneBook {
public:
	PhoneBook( void );
	~PhoneBook( void );
	void get_contact( void );
	void search( void );
private:
	int oldest;
	Contact array[8];
	void print_contact(Contact contact) const;
	std::string limiter(const std::string& str, size_t maxLength) const;
};


bool isnum(const std::string& str);

#endif