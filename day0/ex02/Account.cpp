#include <iostream>
#include "Account.hpp"
#include <ctime>

/* 클래스 정적변수 초기화 */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

