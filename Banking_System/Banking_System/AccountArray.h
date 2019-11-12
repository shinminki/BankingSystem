#pragma once
#include "BankingCommonDecl.h"
#include "Account.h"

typedef Account* ACCOUNT_PTR;

class BoundCheckAccountPtrArray
{
private:
	ACCOUNT_PTR* accArr;
	int arrLen;

	BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr) {} // 배열 클래스도 저장소의 일종이기 때문에
	BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& arr) {} // 복사나 대입을 원칙적으로 private영역에 두어 막아둔다.
public:
	BoundCheckAccountPtrArray(int len);
	ACCOUNT_PTR& operator[] (int idx);
	ACCOUNT_PTR operator[] (int idx) const;
	int GetArrLen() const { return arrLen; }
	~BoundCheckAccountPtrArray() { delete[]accArr; }
};