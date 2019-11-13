/*
* 2019-11-13
* BankingSystem ver 0.4
* 작성자 : 신민기	
* 내용 : TodoList 09 내역 Update & version UP
*			09 - 직접 String 클래스를 정의하여 적용시키기
*			
*																	
*/
#include "BankingCommonDecl.h"
#include "AccountHandler.h"

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