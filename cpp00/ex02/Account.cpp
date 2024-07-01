/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:29:26 by seungryk          #+#    #+#             */
/*   Updated: 2024/07/01 13:30:53 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

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

void _displayTimestamp( void )
{
    std::tm*    local_time;
    std::time_t current_time;
    
    current_time = std::time(NULL);
    local_time = std::localtime(&current_time);
    std::cout << "[";
    std::cout << local_time->tm_year + 1900;
    std::cout << local_time->tm_mon + 1;
    std::cout << local_time->tm_mday;
    std::cout << "_";
    std::cout << local_time->tm_hour;
    std::cout << local_time->tm_min;
    std::cout << local_time->tm_sec;
    std::cout << "] ";
}

Account::Account( int initial_deposit ){
    getNbAccounts();
    getTotalAmount();
    getNbDeposits();
    getNbWithdrawals();
    _displayTimestamp();
    initial_deposit += checkAmount();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";   
    std::cout << "created" << std::endl;
    _accountIndex++;
}


Account::~Account(){
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";   
    std::cout << "closed" << std::endl;
}

void    Account::displayStatus( void ) const{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << ";";
    std::cout << std::endl;
}

void    Account::displayAccountsInfos( void ){
    _displayTimestamp();
    //std::cout << "index:" << idx << ";";
    //std::cout << "amount:" << checkAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << ";";
    std::cout << std::endl;
}

void    Account::makeDeposit( int deposit ){
    _nbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << checkAmount() << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << checkAmount() + deposit << ";";
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;
    _amount += deposit;
}

bool    Account::makeWithdrawal( int withdrawal )
{
    _nbWithdrawals += 1;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << checkAmount() << ";";
    if (checkAmount() - withdrawal < 0)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (1);    
    }
    std::cout << "withdrawal:" << checkAmount() - withdrawal << ";";
    withdrawal = checkAmount() - withdrawal;
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "nb_withdrawals:" << getNbWithdrawals() << std::endl;
    return (0);
}
