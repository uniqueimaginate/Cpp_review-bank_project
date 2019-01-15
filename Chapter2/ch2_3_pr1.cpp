#include <iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
	Point *temp = new Point;
	temp->xpos = p1.xpos + p2.xpos;
	temp->ypos = p1.ypos + p2.ypos;
	return *temp;
}

int main()
{
	Point *num1 = new Point;
	Point *num2 = new Point;
	
	*num1 = {3,5};
	*num2 = {5,8};

	Point &pref = PntAdder(*num1, *num2);

	cout << pref.xpos << endl;
	cout << pref.ypos << endl;

	delete num1;
	delete num2;
	delete &pref;

	return 0;
}
