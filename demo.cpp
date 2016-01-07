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
	
	str5 += str2;
	str4 = str5 + str1;
	str6 = str1 + "12345325";
	
	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	std::cout << str3 << std::endl;
	std::cout << str4 << std::endl;
	std::cout << str5 << std::endl;
	std::cout << str6 << std::endl;

	std::cout << (str1 > str5 ? str1 : str5) << std::endl;
	std::cout << (str1 >= str5 ? str1 : str5) << std::endl;
	std::cout << (str1 < str5 ? str1 : str5) << std::endl;
	std::cout << (str1 <= str5 ? str1 : str5) << std::endl;
	std::cout << (str1 == str5 ? str1 : str5) << std::endl;
	std::cout << (str1 != str5 ? str1 : str5) << std::endl;

	//std::cin >> str7;
	//std::cout << str7 << std::endl;
	
	return 0;
}
