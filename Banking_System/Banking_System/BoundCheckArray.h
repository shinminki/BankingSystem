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

	BoundCheckArray(const BoundCheckArray& arr) {} // 배열 클래스도 저장소의 일종이기 때문에
	BoundCheckArray& operator=(const BoundCheckArray& arr) {} // 복사나 대입을 원칙적으로 private영역에 두어 막아둔다.
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
		cout << " 배열 범위 초과 에러 " << endl;
		exit(1);
	}
	return accArr[idx];
}

template<typename T>
T BoundCheckArray<T>::operator[] (int idx) const
{
	if (idx < 0 || idx >= arrLen)
	{
		cout << " 배열 범위 초과 에러 " << endl;
		exit(1);
	}
	return accArr[idx];
}

