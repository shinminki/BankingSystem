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
	int accID;      //����
	int balance;    //�ܾ�
	string cusName;  //�̸�
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
			cout << "  ���� ID : " << accID << endl;
			cout << "     �̸� : " << cusName << endl;
			cout << "     �ܾ� : " << balance << endl;
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
		cout << "���� : ";
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
	cout << "1. ���°���" << endl;
	cout << "2. �� �� " << endl;
	cout << "3. �� �� " << endl;
	cout << "4. �������� ��ü ��� " << endl;
	cout << "5. ���α׷� ���� " << endl << endl;
}

void MakeAccount(void)
{
	int id;
	string name;
	int balance;

	cout << "              [ ���°��� ]" << endl << endl;
	cout << "    ���� ID : "; cin >> id;
	cout << "      �� �� : "; cin >> name;
	cout << "�⺻ �Աݾ� : "; cin >> balance; cout << endl;

	accArr[accNum] = new Account(id, balance, name);
	accNum++;
}

void DepositMoney(void)
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

void WithdrawMoney(void)
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

void ShowAllAccInfo(void)
{
	cout << "              [ ��ü �������� ]" << endl << endl;

	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << " - - - - - - - - - - - - - - - - - - - " << endl << endl;
	}

	cout << "�� ���� : " << accNum << " / 100 " << endl;
}
