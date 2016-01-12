#include "Mystring.h"
#include <cstring>
#include <cassert>
#include <iostream>

namespace cfm
{
/*构造函数*/
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

/*析构函数*/
MyString::~MyString()
{
	if (NULL != m_str)
	{
		delete []m_str;
		m_str = NULL;
	}
	//std::cout << "~MyString()" << std::endl;
}

/*属性*/
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

/*运算符重载*/
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


/*友元重载运算符*/
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

/*字符串各类操作*/

/*返回下标为pos，长度为len的子串*/
MyString MyString::substr(const size_t pos, const size_t len) const
{
	assert(pos + len <= m_strLen);

	MyString temp;

	temp.m_strLen = len;
	temp.m_str = new char[m_strLen + 1];

	for (int i = 0; i < m_strLen; i++)
	{
		temp.m_str[i] = m_str[pos + i];
	}

	temp.m_str[m_strLen] = '\0';

	return temp;
}

/*连接*/
MyString &MyString::append(const MyString &str)
{
	char *oldStr = m_str;
	
	m_strLen += str.m_strLen;
	m_str = new char[m_strLen + 1];
	strcpy(m_str, oldStr);
	strcat(m_str, str.m_str);
	
	delete []oldStr;

	return *this;
}

/*插入,在下标为pos的字符前面插入str*/
MyString &MyString::insert(const size_t pos, const MyString &str)
{
	assert(pos < m_strLen);

	int i = 0;
	char *oldStr = m_str;
	m_strLen += str.m_strLen;
	m_str = new char[m_strLen + 1];

	for (i = 0; i < pos; i++)
	{
		m_str[i] = oldStr[i];
	}

	for (i = pos; i < pos+str.m_strLen; i++)
	{
		m_str[i] = str.m_str[i - pos];
	}

	for (i = pos+str.m_strLen; i < m_strLen+1; i++)
	{
		m_str[i] = oldStr[i - str.m_strLen];
	}

	m_str[m_strLen] = '\0';
	delete []oldStr;

	return *this;
}

/*删除，从下标为pos开始删除len个字符*/
MyString &MyString::erase(const size_t pos, const size_t len)
{
	assert(pos + len <= m_strLen);

	int i = 0;
	char *oldStr = m_str;
	m_strLen -= len;
	m_str = new char[m_strLen + 1];

	for (i = 0; i < pos; i++)
	{
		m_str[i] = oldStr[i];
	}
	
	for (i = pos; oldStr[i+len] != '\0'; i++)
	{
		m_str[i] = oldStr[i+len];
	}

	m_str[m_strLen] = '\0';
	delete []oldStr;

	return *this;
}

/*查找，从下标为pos开始查找字符c在该字符串中的位置*/
size_t MyString::find(const char c, const size_t pos) const 
{
	assert(pos <= m_strLen);

	for (int i = pos; m_str[i] != '\0'; i++)
	{
		if (c == m_str[i])
		{
			return i;
		}
	}

	return npos;
}

/*查找，从下标为pos开始查找字符串str在该字符串中的位置*/
size_t MyString::find(const MyString &str, const size_t pos) const 
{
	assert(pos <= m_strLen);

	char *p = strstr(m_str + pos, str.m_str);

	if (p != NULL)
	{
		return p - m_str;
	}
	else
	{
		return npos;
	}
}

/*替换，用字符串str替换从下标pos开始长度为len的一截*/
MyString &MyString::replace(const size_t pos, const size_t len, const MyString &str)
{
	assert(pos + len <= m_strLen);

	this->erase(pos, len);
	this->insert(pos, str);
}

}/*end namespace cfm*/

