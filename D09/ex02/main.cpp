/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:04:24 by wayden            #+#    #+#             */
/*   Updated: 2025/06/22 21:42:05 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"


bool isvalidEntry(std::istringstream& iss, int value, std::set<int>& seen)
{
	if(!(!iss.fail() && iss.eof() && value > 0))
		return(ErrorManager::getInstance()->setError(1, ERR_INVALID_ARG),false);
	if(!seen.insert(value).second)
		return(ErrorManager::getInstance()->setError(1, ERR_UNIQUE_ARG),false);
	return true;
}

void parseArgs(int argc, char** argv, std::vector<int>& v_ints, std::deque<int>& dq_ints)
{
	std::set<int> seen;
	if (argc <= MIN_ARGS)
		ErrorManager::getInstance()->exitWithError(1, ERR_NOTENOUGH_ARG);
	for (int i = 2; i < argc; i++)
	{
		std::string str = argv[i];
		std::istringstream iss(str);
		int value;
		iss >> value;
		if (!isvalidEntry(iss, value, seen))
			ErrorManager::getInstance()->exitWithError();
		v_ints.push_back(value);
		dq_ints.push_back(value); // Use push_back for deque	
	}
}

void printBefore(std::vector<int>& v_ints)
{
	std::cout << "Before :";
	for(size_t i = 0; i < v_ints.size(); i++)
		std::cout << " " << v_ints[i];
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
#ifdef DEBUG_BUILD
    std::cout << "DEBUG ACTIVE" << std::endl;
#else
    std::cerr << "DEBUG_BUILD n'est pas défini !" << std::endl;
#endif
	std::vector<int> v_ints;
	std::deque<int> dq_ints;
	parseArgs(argc, argv, v_ints, dq_ints);
	printBefore(v_ints);
#ifdef DEBUG_BUILD
		printVector(v_ints);
		printDeque(dq_ints);
#endif
	return 0;
}