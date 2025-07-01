/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:04:24 by wayden            #+#    #+#             */
/*   Updated: 2025/06/28 23:36:02 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/includes.hpp"

bool isvalidEntry(std::istringstream& iss, int value, std::set<int>& seen)
{
	if(!(!iss.fail() && iss.eof() && value >= 0))
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
	for (int i = 1; i < argc; i++)
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


int main(int argc, char **argv)
{
    std::vector<int> v_ints;
    std::deque<int> dq_ints;

    parseArgs(argc, argv, v_ints, dq_ints);

    printContent(BEFORE, v_ints);

    clock_t start_vec = clock();
    PmergeMe<std::vector>::merge_insert(v_ints,1);
    clock_t end_vec = clock();
    double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1e3;
    clock_t start_deque = clock();
    PmergeMe<std::deque>::merge_insert(dq_ints,1);
    clock_t end_deque = clock();
    double time_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC * 1e3;
	printContent(AFTER, v_ints);
    std::cout << "Time to process a range of " << v_ints.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(6) << time_vec << " ms" << std::endl;
    std::cout << "Time to process a range of " << dq_ints.size()
              << " elements with std::deque  : " << std::fixed << std::setprecision(6) << time_deque << " ms" << std::endl;
    return 0;
}
