#include "BankingCommonDecl.h"
#include "Account.h"


Account& Account::operator=(const Account& ref) {
	accID = ref.accID;
	balance = ref.balance;

	delete[]cusName;
	int len = strlen(ref.cusName) + 1;
	cusName = new char[len];
	strcpy(cusName, ref.cusName);

	return *this;
}

Account::Account(int ID, int money, char* name) :
	accID(ID), balance(money) {

	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
};

Account::Account(const Account& ref) : // ±íÀº º¹»ç »ý¼ºÀÚ
	accID(ref.accID), balance(ref.balance)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
};

int Account::GetAccID() const {
	/*if (this != NULL)
	{
		return accID;
	}*/
	return accID;

}

void Account::Deposit(int money)
{
	balance += money;
}

int Account::Withdraw(int money)
{
	if (balance < money)
		return 0;

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const
{
	if (this != NULL)
	{
		cout << "  °èÁÂ ID : " << accID << endl;
		cout << "     ÀÌ¸§ : " << cusName << endl;
		cout << "     ÀÜ¾× : " << balance << endl;
	}
}

Account::~Account() {
	delete[]cusName;
}