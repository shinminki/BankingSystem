/*
* 2019-11-13
* BankingSystem ver 0.3
* 작성자 : 신민기	
* 내용 : TodoList 08 내역 Update
*			08 - AccountHandler 클래스 내의 배열 멤버를 배열 클래스로 대체
					(BoundCheckPointPtrArray 배열 클래스)
			   - Account 클래스 깊은복사 대입연산자 오버로딩
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