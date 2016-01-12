#include "Mystring.h"

using namespace cfm;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	MyString str1("string1");
	MyString str2(10, 'A');
	MyString str3 = str1;
	MyString str4;
	MyString str5("string5");
	MyString str6;
	//MyString str7;
	MyString str8 = "string8";
	MyString str9 = "string9";
	MyString str10 = "string10";
	
	str5 += str2;
	str4 = str5 + str1;
	str6 = str1 + "12345325";
	str8.append(str2);
	str9.insert(3, str2);
	str10.erase(3, 4);
		
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	cout << "str3: " << str3 << endl;
	cout << "str4: " << str4 << endl;
	cout << "str5: " << str5 << endl;
	cout << "str6: " << str6 << endl;
	cout << "str8: " << str8 << endl;
	cout << "str9: " << str9 << endl;
	cout << "str10: " << str10 << endl;

	cout << (str1 > str5 ? 1 : 0) << endl;
	cout << (str1 >= str5 ? 1 : 0) << endl;
	cout << (str1 < str5 ? 1 : 0) << endl;
	cout << (str1 <= str5 ? 1 : 0) << endl;
	cout << (str1 == str5 ? 1 : 0) << endl;
	cout << (str1 != str5 ? 1 : 0) << endl;

	//std::cin >> str7;
	//std::cout << str7 << std::endl;

	int pos1 = str1.find('i', 0);
	int pos2 = str1.find("ring", 0);
	
	if (pos1 != MyString::npos)
	{
		cout << "pos1 = " << pos1 << endl;
	}

	if (pos2 != MyString::npos)
	{
		cout << "pos2 = " << pos2 << endl;
	}

	MyString str11 = "string11";
	str11.replace(0, 3, str2);
	cout << "After replacing, str11 = " << str11 << endl;

	MyString str12 = "string12";
	MyString substr = str12.substr(6, 2);
	cout << "The substr of str12 = " << substr << endl;
	
	return 0;
}
