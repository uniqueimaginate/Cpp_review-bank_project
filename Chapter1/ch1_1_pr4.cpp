#include <iostream>

int main()
{
	while(true)
	{
		int number;
		const int salary = 50;
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end) : ";
		std::cin >> number;
		if(number == -1)
		{
			std::cout << "프로그램을 종료합니다." << std::endl;
			break;
		}
		else
		{
			std::cout << "이번 달 급여 : " << salary + number*0.12 << "만원" << std::endl;
		}
	}

	return 0;
}
