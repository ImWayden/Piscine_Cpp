/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:36:31 by wayden            #+#    #+#             */
/*   Updated: 2024/01/19 16:57:09 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
# define CALSS_HPP

#include <iostream>

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
	std::string Info[5];
	int  notempty;
private:
};


class PhoneBook {
public:
	PhoneBook( void );
	~PhoneBook( void );
	void get_contact( void );
	void search( void ) const;
private:
	int oldest;
	Contact array[8];
	void print_header( void ) const;
	void print_contact(Contact contact) const;
	std::string limiter(const std::string& str, size_t maxLength) const;
};


bool isnum(const std::string& str);

#endif