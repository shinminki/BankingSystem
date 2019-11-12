#pragma once
#include "BankingCommonDecl.h"
#include "NormalAccount.h"


class HighCreditAccount : public NormalAccount
{
private:
	int grade;
public:
	HighCreditAccount(int id, int mon, char* name, int rate, int grd) : NormalAccount(id, mon, name, rate), grade(grd) {}
	void Deposit(int money) {
		NormalAccount::Deposit(money);
		money = money * (grade / 100.0);
		Account::Deposit(money);
	}
	void ShowAccInfo() const
	{
		cout << " �߰������� " << grade << "%�� �ſ�ŷڰ��� " << endl;
		Account::ShowAccInfo();
	}
	~HighCreditAccount() {}
};