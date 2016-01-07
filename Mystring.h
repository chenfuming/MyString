#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <iostream>

namespace cfm
{
	class MyString
	{
	public:
		/*构造函数*/
		MyString();
		MyString(const char *);
		MyString(const MyString &);
		MyString(const size_t, const char);
		/*析构函数*/
		~MyString();
		/*属性*/
		size_t length();
		bool empty();
		const char *c_str();
		/*运算符重载*/
		MyString &operator = (const MyString &);
		MyString &operator += (const MyString &);
		char &operator[] (const size_t);
		/*友元*/
		friend MyString operator + (const MyString &, const MyString &);
		friend bool operator == (const MyString &, const MyString &);
		friend bool operator != (const MyString &, const MyString &);
		friend bool operator < (const MyString &, const MyString &);
		friend bool operator <= (const MyString &, const MyString &);
		friend bool operator > (const MyString &, const MyString &);
		friend bool operator >= (const MyString &, const MyString &);
		friend std::ostream &operator << (std::ostream &, const MyString &);
		friend std::istream &operator >> (std::istream &, MyString &);
		/*字符串操作函数*/
		MyString &append(const MyString &); //连接
		MyString &insert(const size_t, const MyString &); //插入
		MyString &erase(const size_t, const size_t); //删除
	private:
		size_t m_strLen;
		char *m_str;
	};
	
}

#endif
