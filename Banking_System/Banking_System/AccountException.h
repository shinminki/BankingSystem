#pragma once
#include "BankingCommonDecl.h"

class WithdrawException {
private:
	int balance;
public:
	WithdrawException(int money) : balance(money) {}

	void showExceptionReason()
	{
		cout << " !�ܾ� ERROR! ��ݾ��� �ٽ� �Է����ּ���." <<endl;
	}
};

class MoneyInputException {
private:
	int input;
public:
	MoneyInputException(int money) : input(money) {}

	void showExceptionReason()
	{
		cout << " !�Է� ERROR! �ݾ� �Է��� ����� ���˴ϴ�." << endl;
	}
};