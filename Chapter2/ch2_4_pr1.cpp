#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char *arr = new char[50];
	char arr1[20] = "Hello";
	strcpy(arr, "hello_world");
	cout << arr << endl;
	
	cout << strlen(arr) << endl;

	strcat(arr,"_again");
	cout << arr << endl;

	cout << strcmp(arr1, arr) << endl;
	return 0;
}
