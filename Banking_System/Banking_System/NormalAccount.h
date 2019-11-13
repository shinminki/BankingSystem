#pragma once
#include "BankingCommonDecl.h"
#include "Account.h"

class NormalAccount : public Account
{
private:
	int interRate; // ������ ����
public:
	NormalAccount(int id, int mon, String name, int rate) : Account(id, mon, name), interRate(rate) {}
	void Deposit(int money) {
		money += money * (interRate / 100.0); // �������ڿ� ������ �߰��� �Աݾ�
		Account::Deposit(money); // ���� �Աݾ��� �Ա�

	}
	void ShowAccInfo() const {
		cout << " ������ " << interRate << "% �� ���뿹�ݰ��� " << endl;
		Account::ShowAccInfo();
	}
	~NormalAccount() {}
};