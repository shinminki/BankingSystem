#include "String.h"

String::String() : len(0), str(NULL) {}

String::String(const char* s) {
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}
String::String(const String& s) : len(s.len) { // 깊은 복사 생성자
	//len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}

String::~String() {
	if (str != NULL)
		delete[]str;
}

String& String::operator=(const String& s) { // 대입연산자 깊은 복사
	if (str != NULL)
	{
		delete[]str;
	}
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}

String& String::operator+=(const String& s) {
	len += (s.len - 1);
	char* tmpStr = new char[len];
	strcpy(tmpStr, str);
	strcat(tmpStr, s.str);

	if (str != NULL)
	{
		delete[]str;
	}
	str = tmpStr;

	return *this;
}

String String::operator+(const String& s) {
	len += (s.len - 1);
	char* tmpStr = new char[len];
	strcpy(tmpStr, str);
	strcat(tmpStr, s.str);

	String temp(tmpStr); // tmpStr이 연산결과임. 그 결과를 새로운 String 객체 생성자로 전달
	delete tmpStr; //임시 str 삭제 
	return temp;
}

bool String::operator==(const String& s) {
	if (!strcmp(str, s.str))
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& os, const String& s) {
	os << s.str;
	return os;
}

istream& operator>>(istream& is, String& s) {
	char str[100];
	is >> str;
	s = String(str);
	return is;
}

