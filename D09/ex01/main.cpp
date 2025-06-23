/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 02:06:54 by wayden            #+#    #+#             */
/*   Updated: 2025/06/22 15:30:04 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <string>
#include <iostream>
#include <cstdlib>

bool isoperand(char c){return c == '+' || c == '-' || c == '/' || c == '*';}

void calc(char c, std::stack<int>& stack)
{
	if(stack.size() < 2)
		throw std::exception();
	int b = stack.top();
	stack.pop();
	int a = stack.top();
	stack.pop();
	switch(c)
	{
		case('+'): stack.push(a + b); break;
		case('-'): stack.push(a - b); break;
		case('*'): stack.push(a * b); break;
		case('/'): if(b == 0) throw std::exception(); else stack.push(a / b); break;
	}
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Invalid Args: Usage: ./btc <filename>" << std::endl;
        return 1;
    }
	std::stack<int> stack;
	std::string input = argv[1];
	for(size_t i = 0; i < input.size(); i++)
	{
		if(isdigit(input[i]))
			stack.push(input[i] - '0');
		else if(isoperand(input[i]))
			try{calc(input[i],  stack);}
			catch (const std::exception& e) {
				std::cerr << "Error: " << e.what() << std::endl;
				return 1;
			}
		else
		{
			if(input[i] == ' ') continue;
			std::cerr << "Error: Invalid character detected" << std::endl;
			return 1;
		}
	}
	if (stack.size() != 1) {
		std::cerr << "Error: Invalid expression" << std::endl;
		return 1;
	}
	std::cout << stack.top() << std::endl;
    return 0;
}