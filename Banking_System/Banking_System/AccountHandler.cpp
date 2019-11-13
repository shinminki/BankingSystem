#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"

int AccountHandler::accNum = 0;

AccountHandler::AccountHandler() {}

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
	int accChoice;
	cout << "              [ ������������ ]" << endl << endl;
	cout << " 1. ���뿹�ݰ��� / 2. �ſ�ŷڰ��� " << endl << " ���� : ";

	cin >> accChoice;
	cout << endl;
	switch (accChoice)
	{
	case NORMAL:
		MakeNormalAccount();
		break;
	case HIGHCREDIT:
		MakeHighCreditAccount();
		break;
	default:
		cout << "1,2 �� �ϳ��� �Է��ض�" << endl;
	}
}

void AccountHandler::MakeNormalAccount(void) {
	int id;
	String name;
	int balance;
	int interRate;

	cout << "              [ ���뿹�ݰ��� ���� ]" << endl << endl;
	cout << "    ���� ID : "; cin >> id;
	cout << "      �� �� : "; cin >> name;
	cout << "�⺻ �Աݾ� : "; cin >> balance;
	cout << "     ������ : "; cin >> interRate; cout << endl;

	accArr[accNum] = new NormalAccount(id, balance, name, interRate);
	accNum++;
}

void AccountHandler::MakeHighCreditAccount(void) {
	int id;
	String name;
	int balance;
	int interRate;
	int grade;

	cout << "              [ �ſ�ŷڰ��� ���� ]" << endl << endl;
	cout << "    ���� ID : "; cin >> id;
	cout << "      �� �� : "; cin >> name;
	cout << "�⺻ �Աݾ� : "; cin >> balance;
	cout << "     ������ : "; cin >> interRate;
	cout << "   �ſ��� : "; cin >> grade; cout << endl;

	switch (grade)
	{
	case 1:
		accArr[accNum] = new HighCreditAccount(id, balance, name, interRate, Grade_A);
		break;
	case 2:
		accArr[accNum] = new HighCreditAccount(id, balance, name, interRate, Grade_B);
		break;
	case 3:
		accArr[accNum] = new HighCreditAccount(id, balance, name, interRate, Grade_C);
		break;
	}
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

	cout << "�� ���� : " << accNum << " / " << MAX_ARR << endl;
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	}
}