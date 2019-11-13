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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금 " << endl;
	cout << "3. 출 금 " << endl;
	cout << "4. 계좌정보 전체 출력 " << endl;
	cout << "5. 프로그램 종료 " << endl << endl;
}

void AccountHandler::MakeAccount(void)
{
	int accChoice;
	cout << "              [ 계좌종류선택 ]" << endl << endl;
	cout << " 1. 보통예금계좌 / 2. 신용신뢰계좌 " << endl << " 선택 : ";

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
		cout << "1,2 중 하나를 입력해라" << endl;
	}
}

void AccountHandler::MakeNormalAccount(void) {
	int id;
	String name;
	int balance;
	int interRate;

	cout << "              [ 보통예금계좌 개설 ]" << endl << endl;
	cout << "    계좌 ID : "; cin >> id;
	cout << "      이 름 : "; cin >> name;
	cout << "기본 입금액 : "; cin >> balance;
	cout << "     이자율 : "; cin >> interRate; cout << endl;

	accArr[accNum] = new NormalAccount(id, balance, name, interRate);
	accNum++;
}

void AccountHandler::MakeHighCreditAccount(void) {
	int id;
	String name;
	int balance;
	int interRate;
	int grade;

	cout << "              [ 신용신뢰계좌 개설 ]" << endl << endl;
	cout << "    계좌 ID : "; cin >> id;
	cout << "      이 름 : "; cin >> name;
	cout << "기본 입금액 : "; cin >> balance;
	cout << "     이자율 : "; cin >> interRate;
	cout << "   신용등급 : "; cin >> grade; cout << endl;

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

	cout << "총 계좌 : " << accNum << " / " << MAX_ARR << endl;
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	}
}