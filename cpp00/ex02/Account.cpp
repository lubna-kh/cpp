#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
	: _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";created" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}
void	Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount - deposit
			<< ";deposit:" << deposit
			<< ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits
			<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:refused" << std::endl;
		return false;
	}
	else 
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:" << withdrawal;

		_amount -= withdrawal;
		std::cout << ";amount:" << _amount
				<< ";nb_withdrawals:" << ++_nbWithdrawals
				<< std::endl;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return true;
	}
}



void	Account::_displayTimestamp(void)
{
	time_t now = std::time(0);
	std::tm* localTime = std::localtime(&now);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);
	std::cout << buffer << " ";
}

int		Account::checkAmount( void ) const
{
	return _amount;
}


void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
			<< std::endl;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout<< "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
			<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals()
			<< std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout<< "index:" << _accountIndex << ";amount:"
			<< _amount << ";closed" << std::endl;
}