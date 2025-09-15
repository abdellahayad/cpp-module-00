#include <iostream>
#include <ctime>
#include "Account.hpp"


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals  = 0;

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << checkAmount()
			  << ";created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << checkAmount()
			  << ";closed" << std::endl;
}

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int  Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int  Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";p_amount:" << checkAmount();
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";deposit:" << deposit
			  << ";amount:"  << checkAmount()
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}
 
void	Account::_displayTimestamp( void )
{
	char    buffer[20];

	std::time_t     now = std::time(NULL);
	std::tm         *t  = std::localtime(&now);
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", t);
	std::cout << buffer << " ";
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << checkAmount();
	if (checkAmount() < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal
			  << ";amount:" << checkAmount()
			  << ";nb_withdrawals:" << _nbWithdrawals
			  << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << checkAmount()
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals
			<< std::endl;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
			<< ";total:" << Account::getTotalAmount()
			<< ";deposits:" << Account::getNbDeposits()
			<< ";withdrawals:" << Account::getNbWithdrawals()
			<< std::endl;
}