#pragma once
#include "BankingCommonDecl.h"
#include "Account.h"

typedef Account* ACCOUNT_PTR;

class BoundCheckAccountPtrArray
{
private:
	ACCOUNT_PTR* accArr;
	int arrLen;

	BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr) {} // �迭 Ŭ������ ������� �����̱� ������
	BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& arr) {} // ���糪 ������ ��Ģ������ private������ �ξ� ���Ƶд�.
public:
	BoundCheckAccountPtrArray(int len);
	ACCOUNT_PTR& operator[] (int idx);
	ACCOUNT_PTR operator[] (int idx) const;
	int GetArrLen() const { return arrLen; }
	~BoundCheckAccountPtrArray() { delete[]accArr; }
};