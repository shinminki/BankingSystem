#pragma once

class Account {
private:
	int accID;      //계좌
	int balance;    //잔액
	char* cusName;  //이름
public:
	Account(int ID, int money, char* name);
	Account(const Account& ref); // 깊은 복사생성자
	Account& operator=(const Account& ref); // 대입 연산자의 깊은 복사
	int GetAccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	virtual void ShowAccInfo() const;
	~Account();
};