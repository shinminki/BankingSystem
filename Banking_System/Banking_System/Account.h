#pragma once
#include "String.h"

class Account {
private:
	int accID;      //°èÁÂ
	int balance;    //ÀÜ¾×
	String cusName;  //ÀÌ¸§
public:
	Account(int ID, int money, String name);
	int GetAccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	virtual void ShowAccInfo() const;
};