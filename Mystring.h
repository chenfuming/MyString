#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <iostream>

namespace cfm
{
	class MyString
	{
	public:
		/*���캯��*/
		MyString();
		MyString(const char *);
		MyString(const MyString &);
		MyString(const size_t, const char);
		/*��������*/
		~MyString();
		/*����*/
		size_t length();
		bool empty();
		const char *c_str();
		/*���������*/
		MyString &operator = (const MyString &);
		MyString &operator += (const MyString &);
		char &operator[] (const size_t);
		/*��Ԫ*/
		friend MyString operator + (const MyString &, const MyString &);
		friend bool operator == (const MyString &, const MyString &);
		friend bool operator != (const MyString &, const MyString &);
		friend bool operator < (const MyString &, const MyString &);
		friend bool operator <= (const MyString &, const MyString &);
		friend bool operator > (const MyString &, const MyString &);
		friend bool operator >= (const MyString &, const MyString &);
		friend std::ostream &operator << (std::ostream &, const MyString &);
		friend std::istream &operator >> (std::istream &, MyString &);
		/*�ַ�����������*/
		MyString substr(const size_t, const size_t) const; //�����Ӵ�
		MyString &append(const MyString &); //����
		MyString &insert(const size_t, const MyString &); //����
		MyString &erase(const size_t, const size_t); //ɾ��
		size_t find(const char, const size_t) const; //�����ַ�
		size_t find(const MyString &, const size_t) const; //�����ַ���
		MyString &replace(const size_t, const size_t, const MyString &);//�滻
		
	public:
		static const size_t npos = -1;		
		
	private:
		size_t m_strLen;
		char *m_str;
	};
	
}

#endif
