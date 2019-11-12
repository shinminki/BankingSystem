/*
* 2019-11-13
* BankingSystem ver 0.3
* �ۼ��� : �Źα�	
* ���� : TodoList 08 ���� Update
*			08 - AccountHandler Ŭ���� ���� �迭 ����� �迭 Ŭ������ ��ü
					(BoundCheckPointPtrArray �迭 Ŭ����)
			   - Account Ŭ���� �������� ���Կ����� �����ε�
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