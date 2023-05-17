#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit):_nbDeposits(0)
{
	_amount = initial_deposit;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	_accountIndex = (int)Account::_nbAccounts;
	std::cout<<" index:"<<this->_accountIndex<<";amount:";
	std::cout<<this->_amount<<";created"<<std::endl;
	Account::_totalAmount += _amount;
	Account::_nbAccounts++;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout<<" index:"<<this->_accountIndex<<";amount:";
	std::cout<<this->_amount<<";closed"<<std::endl;
}
int	Account::getNbAccounts(void)
{
    return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout<<" accounts:"<<Account::_nbAccounts<<";total:"<<getTotalAmount();
	std::cout<<";deposits:"<<getNbDeposits()<<";withdrawals:"<<getNbWithdrawals();
	std::cout<<std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::cout<<"[19920104_091532]";
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	 std::cout<<" index:"<< this->_accountIndex <<";amount:"<<this->_amount;
	 std::cout<<";deposits:"<< this->_nbDeposits <<";withdrawals:"<<this->_nbWithdrawals;
	 std::cout<<std::endl;
}

void	Account::makeDeposit( int deposit )
{
	Account::_totalNbDeposits++;
	_displayTimestamp();
	std::cout<<" index:"<<this->_accountIndex<<";p_amount:"<<this->_amount;
	std::cout<<";deposit:"<< deposit;
	std::cout<<";amount:";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	std::cout<< this->_amount<<";nb_deposits:"<<this->_nbDeposits;
	std::cout<<std::endl;
}


int		Account::checkAmount( void ) const
{
	if (this->_amount > 0 && Account::_totalAmount > 0)
	{
		return (1);
	}
	return (0);
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout<<" index:"<<this->_accountIndex<<";p_amount:"<<this->_amount;
	std::cout<<";withdrawal:";

	if ( this->checkAmount() == 1 && this->_amount >= withdrawal)
	{
		Account::_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		std::cout<< withdrawal << ";amount:"<<this->_amount;
		std::cout<<";nb_withdrawals:"<<this->_nbWithdrawals;
		Account::_totalAmount -= withdrawal;
	}
	else
	{
		std::cout<<"refused";
		std::cout<<std::endl;
		return false;
	}
	std::cout<<std::endl;
	return true;
}
