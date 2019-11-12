/*
* 2019-11-12
* BankingSystem ver 0.3
* �ۼ��� : �Źα�	
* ���� : TodoList 06 ~ 07 ���� Update
*			06 - Account Ŭ������ ����ϴ� Ŭ���� �߰�  - NormalAccount(���뿹�ݰ���)
*														- HighCreditAccount(�ſ�ŷڰ���)
*			07 - ���� ����
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