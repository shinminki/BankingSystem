#pragma once

class Account {
private:
	int accID;      //����
	int balance;    //�ܾ�
	char* cusName;  //�̸�
public:
	Account(int ID, int money, char* name);
	Account(const Account& ref); // ���� ���������
	Account& operator=(const Account& ref); // ���� �������� ���� ����
	int GetAccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	virtual void ShowAccInfo() const;
	~Account();
};