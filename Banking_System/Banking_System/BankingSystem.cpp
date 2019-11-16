/*
* 2019-11-16
* BankingSystem ver 0.5
* 작성자 : 신민기	
* 내용 : TodoList 11 내역 Update
*			11 - 예외처리 1. 계좌개설 이후, 예금된 금액보다 더 많은 금액의 출금을 요구할 경우
	    				  2. 계좌개설 이후, 입출금 진행시 사용자로부터 0보다 작은 값을 입력받을 경우

*			
*																	
*/
#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "AccountException.h"

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