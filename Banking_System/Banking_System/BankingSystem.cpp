/*
* 2019-11-12
* BankingSystem ver 0.3
* 작성자 : 신민기	
* 내용 : TodoList 06 ~ 07 내역 Update
*			06 - Account 클래스를 상속하는 클래스 추가  - NormalAccount(보통예금계좌)
*														- HighCreditAccount(신용신뢰계좌)
*			07 - 파일 분할
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