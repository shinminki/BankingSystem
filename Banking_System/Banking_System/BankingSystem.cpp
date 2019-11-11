/*
* BankingSystem ver 0.2
* 작성자 : 신민기	
* 내용 : TodoList 03 ~ 05 내역 Update
			03- 깊은 복사 생성자 정의
			04- const 선언 가능한 모든 멤버함수를 const 선언 
			05- control 클래스 만들기
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account {
private:
	int accID;      //계좌
	int balance;    //잔액
	char* cusName;  //이름
public:
	Account(int ID, int money, char* name);
	Account(const Account& ref);
	int GetAccID() const;
	void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};
Account::Account(int ID, int money, char* name) :
	accID(ID), balance(money) {

	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
};

Account::Account(const Account& ref) :
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
		cout << "  계좌 ID : " << accID << endl;
		cout << "     이름 : " << cusName << endl;
		cout << "     잔액 : " << balance << endl;
	}
}

Account::~Account() {
	delete[]cusName;
}

class AccountHandler {
private:
	Account* accArr[100];
	int accNum = 0;

public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllAccInfo() const;
	~AccountHandler();

};

AccountHandler::AccountHandler() : accNum(0) {  }

void AccountHandler::ShowMenu(void) const
{
	cout << endl;
	cout << "------MENU------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금 " << endl;
	cout << "3. 출 금 " << endl;
	cout << "4. 계좌정보 전체 출력 " << endl;
	cout << "5. 프로그램 종료 " << endl << endl;
}

void AccountHandler::MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "              [ 계좌개설 ]" << endl << endl;
	cout << "    계좌 ID : "; cin >> id;
	cout << "      이 름 : "; cin >> name;
	cout << "기본 입금액 : "; cin >> balance; cout << endl;

	accArr[accNum] = new Account(id, balance, name);
	accNum++;
}

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;

	cout << "              [ 입 금 ]" << endl << endl;
	cout << "    계좌 ID : "; cin >> id;
	cout << "     입금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{

		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);

			cout << "    입금완료    " << endl << endl;
			return;
		}

	}

	cout << " 일치하는 ID가 존재하지 않습니다... " << endl << endl;
	return;
}

void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;

	cout << "              [ 출 금 ]" << endl << endl;
	cout << "    계좌 ID : "; cin >> id;
	cout << "     출금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{

				cout << " 잔액이 부족합니다... " << endl;
				return;
			}

			cout << "출금완료" << endl;

			return;
		}
	}

	cout << " 일치하는 ID가 존재하지 않습니다... " << endl << endl;
}

void AccountHandler::ShowAllAccInfo(void) const
{
	cout << "              [ 전체 계좌정보 ]" << endl << endl;

	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << " - - - - - - - - - - - - - - - - - - - " << endl << endl;
	}

	cout << "총 계좌 : " << accNum << " / 100 " << endl;
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	}
}

int main()
{
	int choice;
	AccountHandler manager;

	while (1)
	{
		manager.ShowMenu();
		cout << "선택 : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
			break;
		default:
			cout << "비정상적인 선택입니다..." << endl;

		}

	}

	return 0;
}