#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountException.h"


Account::Account(int ID, int money, String name) :
	accID(ID), balance(money) {
	cusName = name;
};

int Account::GetAccID() const {	return accID; }

int Account::GetBalance() const { return balance; }

void Account::Deposit(int money) throw (MoneyInputException)
{
	if (money < 0){
		MoneyInputException exmi(money);
		throw exmi;
	}
	balance += money;
}

int Account::Withdraw(int money) throw (WithdrawException)
{
	if (money < 0) {
		MoneyInputException exmi(money);
		throw exmi;
	}
	if (balance < money) {
		WithdrawException exwi(money);
		throw exwi;
	}
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

