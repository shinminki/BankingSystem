/*
* 2019-11-16
* BankingSystem ver 0.41
* �ۼ��� : �Źα�	
* ���� : TodoList 10 ���� Update
*			10 - �迭 Ŭ����(BoundCheckPointPtrArray)�� Ŭ���� ���ø����� �����ϱ�
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