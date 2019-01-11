#include <iostream>

int main()
{
	int total = 0;
	int num;
	for(int i = 1; i<6; i++)
	{
		std::cout << i << "번째 정수 입력: ";
		std::cin >> num;
		total += num;
	}

	std::cout << "합계: " << total << std::endl;

	return 0;
}
