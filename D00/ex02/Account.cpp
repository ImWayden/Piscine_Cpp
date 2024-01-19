/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:34:18 by wayden            #+#    #+#             */
/*   Updated: 2024/01/19 22:26:21 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit){
	_nbAccounts++;
	_totalAmount += this->_amount;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl; 
	return;	
}

Account::~Account( void ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	return;
}


int	Account::getNbAccounts( void ){
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ){
	return _totalAmount;
}

int	Account::getNbDeposits( void ){
	return _totalNbDeposits;;
}

int	Account::getNbWithdrawals( void ){
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"\
	<< "p_amount:" << this->_amount << ";";
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "deposit:" << deposit << ";"\
	<< "amount:" << this->_amount << ";"\
	<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"\
	<< "p_amount:" << this->_amount << ";"\
	<< "withdrawal:";
	if(withdrawal > this->_amount)
		return(std::cout << "refused" << std::endl, false);
	else{
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << withdrawal << ";"\
		<< "amount:" << this->_amount << ";"\
		<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	
}

int		Account::checkAmount( void ) const{
	return this->_amount;
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"\
	<< "amount:" << this->_amount << ";"\
	<< "deposits:" << this->_nbDeposits << ";"\
	<< "withdrawals:" << this->_nbWithdrawals << std::endl;	
}

void	Account::_displayTimestamp( void )
{
	std::time_t rawTime = std::time(nullptr);
    std::tm *timeInfo = std::localtime(&rawTime);
	char buffer[16];
	
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeInfo);
	std::cout << "[" << buffer << "] ";
}








/*

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

tests.cpp:(.text+0x25c): undefined reference to `Account::displayAccountsInfos()'
/usr/bin/ld: tests.cpp:(.text+0x263): undefined reference to `Account::displayStatus() const'
/usr/bin/ld: tests.cpp:(.text+0x34f): undefined reference to `Account::makeDeposit(int)'
/usr/bin/ld: tests.cpp:(.text+0x37b): undefined reference to `Account::displayAccountsInfos()'
/usr/bin/ld: tests.cpp:(.text+0x382): undefined reference to `Account::displayStatus() const'
/usr/bin/ld: tests.cpp:(.text+0x45d): undefined reference to `Account::makeWithdrawal(int)'
/usr/bin/ld: tests.cpp:(.text+0x489): undefined reference to `Account::displayAccountsInfos()'
/usr/bin/ld: tests.cpp:(.text+0x490): undefined reference to `Account::displayStatus() const'
*/