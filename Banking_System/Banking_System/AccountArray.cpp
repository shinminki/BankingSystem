#include "BankingCommonDecl.h"
#include "AccountArray.h"


ACCOUNT_PTR& BoundCheckAccountPtrArray::operator[] (int idx)
{
	if (idx < 0 || idx >= arrLen)
	{
		cout << " 배열 범위 초과 에러 " << endl;
		exit(1);
	}
	return accArr[idx];
}

ACCOUNT_PTR BoundCheckAccountPtrArray::operator[] (int idx) const
{
	if (idx < 0 || idx >= arrLen)
	{
		cout << " 배열 범위 초과 에러 " << endl;
		exit(1);
	}
	return accArr[idx];
}