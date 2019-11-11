/*
* BankingSystem ver 0.2
* �ۼ��� : �Źα�	
* ���� : TodoList 03 ~ 05 ���� Update
			03- ���� ���� ������ ����
			04- const ���� ������ ��� ����Լ��� const ���� 
			05- control Ŭ���� �����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account {
private:
	int accID;      //����
	int balance;    //�ܾ�
	char* cusName;  //�̸�
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
		cout << "  ���� ID : " << accID << endl;
		cout << "     �̸� : " << cusName << endl;
		cout << "     �ܾ� : " << balance << endl;
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
	cout << "1. ���°���" << endl;
	cout << "2. �� �� " << endl;
	cout << "3. �� �� " << endl;
	cout << "4. �������� ��ü ��� " << endl;
	cout << "5. ���α׷� ���� " << endl << endl;
}

void AccountHandler::MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "              [ ���°��� ]" << endl << endl;
	cout << "    ���� ID : "; cin >> id;
	cout << "      �� �� : "; cin >> name;
	cout << "�⺻ �Աݾ� : "; cin >> balance; cout << endl;

	accArr[accNum] = new Account(id, balance, name);
	accNum++;
}

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;

	cout << "              [ �� �� ]" << endl << endl;
	cout << "    ���� ID : "; cin >> id;
	cout << "     �Աݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{

		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);

			cout << "    �ԱݿϷ�    " << endl << endl;
			return;
		}

	}

	cout << " ��ġ�ϴ� ID�� �������� �ʽ��ϴ�... " << endl << endl;
	return;
}

void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;

	cout << "              [ �� �� ]" << endl << endl;
	cout << "    ���� ID : "; cin >> id;
	cout << "     ��ݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{

				cout << " �ܾ��� �����մϴ�... " << endl;
				return;
			}

			cout << "��ݿϷ�" << endl;

			return;
		}
	}

	cout << " ��ġ�ϴ� ID�� �������� �ʽ��ϴ�... " << endl << endl;
}

void AccountHandler::ShowAllAccInfo(void) const
{
	cout << "              [ ��ü �������� ]" << endl << endl;

	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << " - - - - - - - - - - - - - - - - - - - " << endl << endl;
	}

	cout << "�� ���� : " << accNum << " / 100 " << endl;
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
		cout << "���� : ";
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
			cout << "���������� �����Դϴ�..." << endl;

		}

	}

	return 0;
}