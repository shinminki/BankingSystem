#include <iostream>
#include <cstring>

using namespace std;

//const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account {
private:
	int accID;      //계좌
	int balance;    //잔액
	string cusName;  //이름
public:
	Account(int ID, int mon, string name) :
		accID(ID), balance(mon), cusName(name) {
		
		//cusName = new char[strlen(name) + 1];
		//strcpy(cusName, name);
	};

	int GetAccID() {
		if (this != NULL)
		{
			return accID;
		}
	}

	void Deposit(int money)
	{
		balance += money;
	}

	int Withdraw(int money)
	{
		if (balance < money)
			return 0;

		balance -= money;
		return money;
	}

	void ShowAccInfo()
	{
		if (this != NULL)
		{
			cout << "  계좌 ID : " << accID << endl;
			cout << "     이름 : " << cusName << endl;
			cout << "     잔액 : " << balance << endl;
		}
	}
};

Account* accArr[100];
int accNum = 0;

int main()
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "선택 : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			for (int i = 0; i < accNum; i++)
			{
				delete accArr[i];
			}
			return 0;
			break;
		}
		
	}

	return 0;
}

void ShowMenu(void)
{
	cout << endl;
	cout << "------MENU------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금 " << endl;
	cout << "3. 출 금 " << endl;
	cout << "4. 계좌정보 전체 출력 " << endl;
	cout << "5. 프로그램 종료 " << endl << endl;
}

void MakeAccount(void)
{
	int id;
	string name;
	int balance;

	cout << "              [ 계좌개설 ]" << endl << endl;
	cout << "    계좌 ID : "; cin >> id;
	cout << "      이 름 : "; cin >> name;
	cout << "기본 입금액 : "; cin >> balance; cout << endl;

	accArr[accNum] = new Account(id, balance, name);
	accNum++;
}

void DepositMoney(void)
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

void WithdrawMoney(void)
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

void ShowAllAccInfo(void)
{
	cout << "              [ 전체 계좌정보 ]" << endl << endl;

	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << " - - - - - - - - - - - - - - - - - - - " << endl << endl;
	}

	cout << "총 계좌 : " << accNum << " / 100 " << endl;
}
