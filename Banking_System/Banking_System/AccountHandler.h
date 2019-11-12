#pragma once
#include "Account.h"
#include "AccountArray.h"

class AccountHandler {
private:
	//Account* accArr[100];
	BoundCheckAccountPtrArray accArr;
	static int accNum;

public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void MakeNormalAccount();
	void MakeHighCreditAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllAccInfo() const;
	~AccountHandler();

};
