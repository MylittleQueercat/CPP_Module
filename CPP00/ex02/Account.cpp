#include "Account.hpp"
#include <iostream>
#include <ctime>

// 账户数量；所有账户总额；所有存款操作次数；所有取款操作次数
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// 打印时间戳[YYYYMMDD_HHMMSS]
// tm_year是从1900年算起的偏移量
// tm_mon是从0开始计算的
void	Account::_displayTimestamp(void){
	std::time_t t = std::time(NULL);
	std::tm * tm = std::localtime(&t);

	std::cout << "["
			  << (tm->tm_year + 1900)
			  << (tm->tm_mon + 1 < 10 ? "0" : "") << tm->tm_mon + 1
			  << (tm->tm_mday < 10 ? "0" : "") << tm->tm_mday << "_"
			  << (tm->tm_hour < 10 ? "0" : "") << tm->tm_hour
			  << (tm->tm_min < 10 ? "0" : "") << tm->tm_min
			  << (tm->tm_sec < 10 ? "0" : "") << tm->tm_sec
			  << "] ";
}

// 构造函数
Account::Account(int initial_deposit) {
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created" << std::endl;
}

// 析构函数
Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";closed" << std::endl;
}

// 静态函数
int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
			  << ";total:" << getTotalAmount()
			  << ";deposits:" << getNbDeposits()
			  << ";withdrawals:" << getNbWithdrawals()
			  << std::endl;
}

//成员函数
int	Account::checkAmount(void) const {
	return (this->_amount);
}

void	Account::makeDeposit(int deposit) {
	int	p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << p_amount
			  << ";deposit:" << deposit
			  << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits
			  << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	int	p_amount = this->_amount;

	//打印时间戳、账户编号、取钱前余额
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << p_amount;
	
	//判断余额是否足够
	if (withdrawal > this->_amount) {
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	
	std::cout << ";withdrawal:" << withdrawal
			  << ";amount:" << this->_amount
			  << ";nb_withdrawals:" << this->_nbWithdrawals
			  << std::endl;
	
	return (true);
}

void	Account::displayStatus(void) const{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals
			  << std::endl;
}