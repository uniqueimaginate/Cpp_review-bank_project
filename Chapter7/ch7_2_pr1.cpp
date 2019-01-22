#include <iostream>
using namespace std;

class Rectangle
{
private:
    int result;
public:
    Rectangle(int num1, int num2)
    {
        result = num1 * num2;
    }
    void ShowAreaInfo()
    {
        cout << "면적: " << result << endl;
    }
};

class Square : public Rectangle
{
public:
    Square(int x) : Rectangle(x,x)
    {}
};

int main(void)
{
    Rectangle rec(4,3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}
