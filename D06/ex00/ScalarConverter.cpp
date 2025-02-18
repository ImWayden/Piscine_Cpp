/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:18:25 by wayden            #+#    #+#             */
/*   Updated: 2025/02/14 01:25:25 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

bool isInt(std::string str)
{
	size_t length = str.length();
	if (str.empty()) return false;

	bool isNeg =  str[0] == '-';
	bool hasSign = isNeg || str[0] == '+';
    int start = (hasSign) ? 1 : 0;

    if (start == 1 && str.size() == 1) return false;
    if ((int)length > 10 + hasSign) return false;  
    if ((int)length < 10) return true;

    std::string intMax = "2147483647";
    std::string intMin = "2147483648";
    return (!isNeg && str.substr(start) <= intMax) || (isNeg && str.substr(start) <= intMin);
}

e_type findtype(std::string literal)
{
	size_t lenght = literal.length();
	size_t i = 0;
	bool digits = false;
	if ((lenght == 3) && literal[0] == '\'' && literal[2] == '\'')
		return CHAR;
	if(literal[i] == '+' || literal[i] == '-')
		i++;
	if(literal.substr(i) == "nanf" || literal.substr(i) == "inff")
		return FLOAT;
	if(literal.substr(i) == "nan" || literal.substr(i) == "inf")
		return DOUBLE;
	while(std::isdigit(literal[i])) //could cause problems if literal = "+" or "-" without any digits
	{
		i++;
		digits = true;		
	}
	if(i == lenght && digits && isInt(literal))
		return INT;
	if(literal[i] == '.')
		i++;
	while(std::isdigit(literal[i])) //could cause problems if literal = "+" or "-" without any digits nor "'"
		i++;
	if(i == lenght && digits)
		return DOUBLE;
	else if(literal[i] == 'f' && i+1 == lenght && digits)
		return FLOAT;
	return NOP;
}

int setFlags(double nb)
{
	int flags = 0;
	if(nb < 32 || nb > 126)
		flags = flags | NONDISPLAYABLE;
	if(nb > std::numeric_limits<char>::max() || nb< std::numeric_limits<char>::min())
		flags = flags | OVERFLOWCHAR;
	if(nb> __INT_MAX__ || nb < std::numeric_limits<int>::min())
		flags = flags | OVERFLOWINT;
	if(nb!= nb)
		flags = flags | NANNED;
	return flags;	
}

int convert2Char(std::string lit, double *d, char *c, int *i, float *f)
{
	*c = lit[1];
	int flags = setFlags((double)*c);
	*i = static_cast<int>(*c);
	*f = static_cast<float>(*c);
	*d = static_cast<double>(*c);
	return flags;
}

int convert2Int(std::string lit, double *d, char *c, int *i, float *f)
{
	*i = std::atoi(lit.c_str());
	int flags = setFlags((double)*i);
	*c = static_cast<char>(*i);
	*f = static_cast<float>(*i);
	*d = static_cast<double>(*i);
	return flags;
}

int convert2Float(std::string lit, double *d, char *c, int *i, float *f)
{
	*f = std::atof(lit.c_str());
	int flags = setFlags((double)*f);
	*c = static_cast<char>(*f);
	*i = static_cast<int>(*f);
	*d = static_cast<double>(*f);
	return flags;
}

int convert2Double(std::string lit, double *d, char *c, int *i, float *f)
{
	*d = std::atof(lit.c_str());
	int flags = setFlags((double)*d);
	*c = static_cast<char>(*d);
	*i = static_cast<int>(*d);
	*f = static_cast<float>(*d);
	return flags;
}

void printconvert(int flags, double d = 0, char c = 0, int i = 0, float f = 0)
{
	std::cout << "char : ";
	if(flags & OVERFLOWCHAR || flags & NANNED || flags & NOPPED)
		std::cout << "Impossible" << std::endl;
	else if (flags & NONDISPLAYABLE)
		std::cout << "Non Displayable" << std::endl;
	else
		std::cout << c << std::endl;
	std::cout << "int : ";
	if (flags & OVERFLOWINT || flags & NANNED || flags & NOPPED)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << i << std::endl;
	std::cout << "float : ";
	if (flags & NOPPED)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double : ";
	if (flags & NOPPED)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}


void ScalarConverter::convert(std::string literal)
{
	char c = 0;
	int i = 0;
	float f = 0;
	double d = 0;
	int flags= 0; 
	Converters functions[] = {convert2Char, convert2Int, convert2Float, convert2Double};
	e_type type = findtype(literal);
	if(type != NOP)
	{
		flags = functions[type](literal, &d, &c, &i, &f);
		printconvert(flags, d, c, i, f);
	}
	else
		printconvert(NOPPED);
}
