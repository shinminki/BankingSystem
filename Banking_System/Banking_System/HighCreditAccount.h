#pragma once
#include "BankingCommonDecl.h"
#include "NormalAccount.h"


class HighCreditAccount : public NormalAccount
{
private:
	int grade;
public:
	HighCreditAccount(int id, int mon, String name, int rate, int grd) : NormalAccount(id, mon, name, rate), grade(grd) {}
	void Deposit(int money) {
		NormalAccount::Deposit(money); // 보통예금 이자율 계산 후 입금
		money = money * (grade / 100.0); // 특별이자 계산
		Account::Deposit(money); // 특별이자분 입금
	}
	void ShowAccInfo() const
	{
		cout << " 추가이율이 " << grade << "%인 신용신뢰계좌 " << endl;
		Account::ShowAccInfo();
	}
	~HighCreditAccount() {}
};