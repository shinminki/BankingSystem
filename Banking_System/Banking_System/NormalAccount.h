#pragma once
#include "BankingCommonDecl.h"
#include "Account.h"

class NormalAccount : public Account
{
private:
	int interRate; // 이자율 단위
public:
	NormalAccount(int id, int mon, String name, int rate) : Account(id, mon, name), interRate(rate) {}
	void Deposit(int money) {
		money += money * (interRate / 100.0); // 보통이자와 원금이 추가된 입금액
		Account::Deposit(money); // 위의 입금액을 입금

	}
	void ShowAccInfo() const {
		cout << " 이율이 " << interRate << "% 인 보통예금계좌 " << endl;
		Account::ShowAccInfo();
	}
	~NormalAccount() {}
};