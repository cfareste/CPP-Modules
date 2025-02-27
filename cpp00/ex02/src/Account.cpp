#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return 0;
}

int	Account::getTotalAmount(void)
{
	return 0;
}

int	Account::getNbDeposits(void)
{
	return 0;
}

int	Account::getNbWithdrawals(void)
{
	return 0;
}

void	Account::displayAccountsInfos(void)
{
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
}

void	Account::makeDeposit(int deposit)
{
	(void) deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	(void) withdrawal;
	return false;
}

int	Account::checkAmount(void) const
{
	return 0;
}

void	Account::displayStatus(void) const
{
}

void	Account::_displayTimestamp(void)
{
    std::time_t	t = std::time(nullptr);
    std::tm*	now = std::localtime(&t);

    std::cout << std::put_time(now, "[%Y%m%d_%H%M%S] ");
}
