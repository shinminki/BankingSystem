/*
* 2019-11-16
* BankingSystem ver 0.5
* �ۼ��� : �Źα�	
* ���� : TodoList 11 ���� Update
*			11 - ����ó�� 1. ���°��� ����, ���ݵ� �ݾ׺��� �� ���� �ݾ��� ����� �䱸�� ���
	    				  2. ���°��� ����, ����� ����� ����ڷκ��� 0���� ���� ���� �Է¹��� ���

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