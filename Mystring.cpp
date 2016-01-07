#include "Mystring.h"
#include <cstring>
#include <iostream>

namespace cfm
{
/*���캯��*/
MyString::MyString() : m_str(NULL), m_strLen(0) {}

MyString::MyString(const char *str)
{
	m_strLen = strlen(str);
	m_str = new char[m_strLen + 1];
	strcpy(m_str, str);
}

MyString::MyString(const MyString &str)
{
	m_strLen = str.m_strLen;
	m_str = new char[m_strLen + 1];
	strcpy(m_str, str.m_str);
}

MyString::MyString(const size_t size, const char c)
{
	m_strLen = size;
	m_str = new char[m_strLen + 1];

	for (int i = 0; i < m_strLen; i++)
	{
		m_str[i] = c;
	}

	m_str[m_strLen] = '\0';
}

/*��������*/
MyString::~MyString()
{
	if (NULL != m_str)
	{
		delete []m_str;
		m_str = NULL;
	}
	//std::cout << "~MyString()" << std::endl;
}

/*����*/
size_t MyString::length()
{
	return m_strLen;
}

bool MyString::empty()
{
	return m_strLen == 0? true : false;
}

const char *MyString::c_str()
{
	return m_str;
}

/*���������*/
MyString &MyString::operator = (const MyString &str)
{
	if (this != &str)
	{
		delete []m_str;
		m_strLen = str.m_strLen;
		m_str = new char[m_strLen + 1];
		strcpy(m_str, str.m_str);
	}

	return *this;
}

MyString &MyString::operator += (const MyString &str)
{
	char *oldStr = m_str;
	m_strLen += str.m_strLen;
	
	m_str = new char[m_strLen + 1];
	strcpy(m_str, oldStr);
	strcat(m_str, str.m_str);
	delete []oldStr;

	return *this;
}

char &MyString::operator[] (const size_t index)
{
	return m_str[index];
}


/*��Ԫ���������*/
MyString operator + (const MyString &leftStr, const MyString &rightStr)
{
	MyString temp;

	temp.m_strLen = leftStr.m_strLen + rightStr.m_strLen;
	temp.m_str = new char[temp.m_strLen + 1];
	strcpy(temp.m_str, leftStr.m_str);
	strcat(temp.m_str, rightStr.m_str);

	return temp;
}

bool operator == (const MyString &leftStr, const MyString &rightStr)
{
	return (strcmp(leftStr.m_str, rightStr.m_str) == 0);
}

bool operator != (const MyString &leftStr, const MyString &rightStr)
{
	return (strcmp(leftStr.m_str, rightStr.m_str) != 0);
}

bool operator < (const MyString &leftStr, const MyString &rightStr)
{
	return (strcmp(leftStr.m_str, rightStr.m_str) < 0);
}

bool operator <= (const MyString &leftStr, const MyString &rightStr)
{
	return (strcmp(leftStr.m_str, rightStr.m_str) <= 0);
}

bool operator > (const MyString &leftStr, const MyString &rightStr)
{
	return (strcmp(leftStr.m_str, rightStr.m_str) > 0);
}

bool operator >= (const MyString &leftStr, const MyString &rightStr)
{
	return (strcmp(leftStr.m_str, rightStr.m_str) >= 0);
}

std::ostream &operator << (std::ostream &os, const MyString &str)
{
	os << str.m_str;
	return os;
}

std::istream &operator >> (std::istream &is, MyString &str)
{
	char temp[1024];

	if (is >> temp)
	{
		if (NULL != str.m_str)
		{
			delete []str.m_str;
		}

		str.m_strLen = strlen(temp);
		str.m_str = new char[str.m_strLen + 1];
		strcpy(str.m_str, temp);
	}
	
	return is;
}
		
}/*end namespace cfm*/

