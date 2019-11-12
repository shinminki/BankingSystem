#pragma once
#include "BankingCommonDecl.h"
#include "Account.h"

typedef Account* ACCOUNT_PTR;

class BoundCheckAccountPtrArray
{
private:
	ACCOUNT_PTR* accArr;
	int arrLen;

	BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr) {}
	BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& arr) {}
public:
	BoundCheckAccountPtrArray(int len) : arrLen(len) {
		accArr = new ACCOUNT_PTR[len];
	}
	ACCOUNT_PTR& operator[] (int idx);
	ACCOUNT_PTR operator[] (int idx) const;
	int GetArrLen() const { return arrLen; }
	~BoundCheckAccountPtrArray() { delete[]accArr; }
};