#include "Mystring.h"

using namespace cfm;

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
		
	std::cout << "str1: " << str1 << std::endl;
	std::cout << "str2: " << str2 << std::endl;
	std::cout << "str3: " << str3 << std::endl;
	std::cout << "str4: " << str4 << std::endl;
	std::cout << "str5: " << str5 << std::endl;
	std::cout << "str6: " << str6 << std::endl;
	std::cout << "str8: " << str8 << std::endl;
	std::cout << "str9: " << str9 << std::endl;
	std::cout << "str10: " << str10 << std::endl;

	std::cout << (str1 > str5 ? 1 : 0) << std::endl;
	std::cout << (str1 >= str5 ? 1 : 0) << std::endl;
	std::cout << (str1 < str5 ? 1 : 0) << std::endl;
	std::cout << (str1 <= str5 ? 1 : 0) << std::endl;
	std::cout << (str1 == str5 ? 1 : 0) << std::endl;
	std::cout << (str1 != str5 ? 1 : 0) << std::endl;

	//std::cin >> str7;
	//std::cout << str7 << std::endl;
	
	return 0;
}
