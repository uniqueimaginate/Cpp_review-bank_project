#include <iostream>

int main()
{
	char name[100];
	char phone[100];

	std::cout << "input name : ";
	std::cin >> name;

	std::cout << "input phonenumber : ";
	std::cin >> phone;

	std::cout << name << std::endl;
	std::cout << phone << std::endl;

	return 0;
}
