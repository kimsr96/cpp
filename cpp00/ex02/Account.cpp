/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:29:26 by seungryk          #+#    #+#             */
/*   Updated: 2024/09/10 14:13:16 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void ){
    return (_nbAccounts);
}

int Account::getTotalAmount( void ){
    return (_totalAmount);
}

int Account::getNbDeposits( void ){
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void ){
    return (_totalNbWithdrawals);
}

int Account::checkAmount( void ) const{
    return (_amount);
}

void Account::_displayTimestamp( void )
{
    std::tm*    local_time;
    std::time_t current_time;
    
    current_time = std::time(NULL);
    local_time = std::localtime(&current_time);
    std::cout << "[";
    std::cout << local_time->tm_year + 1900;
    std::cout << std::setfill('0') << std::setw(2) << local_time->tm_mon + 1;
    std::cout << std::setfill('0') << std::setw(2) << local_time->tm_mday;
    std::cout << "_";
    std::cout << std::setfill('0') << std::setw(2) << local_time->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << local_time->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << local_time->tm_sec;
    std::cout << "] ";
}

Account::Account( int initial_deposit ){
    this -> _accountIndex = _nbAccounts;
    this -> _amount = initial_deposit;
    _nbAccounts++;
    _totalAmount += _amount;
    
    _displayTimestamp();
    initial_deposit += checkAmount();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";   
    std::cout << "created" << std::endl;
}

Account::Account(){
}

Account::~Account(){
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";   
    std::cout << "closed" << std::endl;
}

void    Account::displayStatus( void ) const{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << ";";
    std::cout << std::endl;
}

void    Account::displayAccountsInfos( void ){
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << ";";
    std::cout << std::endl;
}

void    Account::makeDeposit( int deposit ){
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << checkAmount() << ";";
    std::cout << "deposit:" << deposit << ";";
    _amount += deposit;
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << checkAmount() << ";";
    if (checkAmount() - withdrawal < 0)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (1);    
    }
    std::cout << "withdrawal:" << withdrawal << ";";
    _amount = checkAmount() - withdrawal;
    std::cout << "amount:" << _amount << ";";
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (0);
}
