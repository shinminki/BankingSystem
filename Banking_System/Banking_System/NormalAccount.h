#pragma once
#include "BankingCommonDecl.h"
#include "Account.h"

class NormalAccount : public Account
{
private:
	int interRate;
public:
	NormalAccount(int id, int mon, char* name, int rate) : Account(id, mon, name), interRate(rate) {}
	void Deposit(int money) {
		money += money * (interRate / 100.0);
		Account::Deposit(money);

	}
	void ShowAccInfo() const {
		cout << " 이율이 " << interRate << "% 인 보통예금계좌 " << endl;
		Account::ShowAccInfo();
	}
	~NormalAccount() {}
};