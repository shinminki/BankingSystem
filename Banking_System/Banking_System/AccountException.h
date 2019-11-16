#pragma once
#include "BankingCommonDecl.h"

class WithdrawException {
private:
	int balance;
public:
	WithdrawException(int money) : balance(money) {}

	void showExceptionReason()
	{
		cout << " !잔액 ERROR! 출금액을 다시 입력해주세요." <<endl;
	}
};

class MoneyInputException {
private:
	int input;
public:
	MoneyInputException(int money) : input(money) {}

	void showExceptionReason()
	{
		cout << " !입력 ERROR! 금액 입력은 양수만 허용됩니다." << endl;
	}
};