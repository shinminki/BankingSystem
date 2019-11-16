#pragma once
#include "String.h"
#include "AccountException.h"


class Account {
private:
	int accID;      //����
	int balance;    //�ܾ�
	String cusName;  //�̸�
public:
	Account(int ID, int money, String name);
	int GetAccID() const;
	int GetBalance() const;
	virtual void Deposit(int money) throw (MoneyInputException);
	int Withdraw(int money) throw (WithdrawException);
	virtual void ShowAccInfo() const;
};