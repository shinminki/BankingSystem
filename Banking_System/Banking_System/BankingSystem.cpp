/*
* 2019-11-16
* BankingSystem ver 0.41
* 작성자 : 신민기	
* 내용 : TodoList 10 내역 Update
*			10 - 배열 클래스(BoundCheckPointPtrArray)를 클래스 템플릿으로 정의하기
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