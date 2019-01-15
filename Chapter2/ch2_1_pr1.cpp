#include <iostream>
using namespace std;

void increment(int &num)
{
	int temp = ++num;
	num = temp;
}
void changeSign(int &num)
{
	int temp = -num;
	num = temp;
}

int main()
{
	int val1 = 10;
	increment(val1);
	cout << val1 << endl;
	changeSign(val1);
	cout << val1 << endl;
	return 0;
}

