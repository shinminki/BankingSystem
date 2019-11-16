#pragma once
#include "BankingCommonDecl.h"
#include "Account.h"

//typedef Account* ACCOUNT_PTR;

template <typename T> 
class BoundCheckArray
{
private:
	T* accArr;
	int arrLen;

	BoundCheckArray(const BoundCheckArray& arr) {} // �迭 Ŭ������ ������� �����̱� ������
	BoundCheckArray& operator=(const BoundCheckArray& arr) {} // ���糪 ������ ��Ģ������ private������ �ξ� ���Ƶд�.
public:
	BoundCheckArray(int len);
	T& operator[] (int idx);
	T operator[] (int idx) const;
	int GetArrLen() const { return arrLen; }
	~BoundCheckArray() { delete[]accArr; }
};

template<typename T>
BoundCheckArray<T>::BoundCheckArray(int len) : arrLen(len) {
	accArr = new T[len];
}

template<typename T>
T& BoundCheckArray<T>::operator[] (int idx)
{
	if (idx < 0 || idx >= arrLen)
	{
		cout << " �迭 ���� �ʰ� ���� " << endl;
		exit(1);
	}
	return accArr[idx];
}

template<typename T>
T BoundCheckArray<T>::operator[] (int idx) const
{
	if (idx < 0 || idx >= arrLen)
	{
		cout << " �迭 ���� �ʰ� ���� " << endl;
		exit(1);
	}
	return accArr[idx];
}

