#include <iostream>

using namespace std;

class Calculator
{
private:
    double numAdd;
    double numSub;
    double numMul;
    double numDiv;

public:
    void Init()
    {
        numAdd = 0;
        numSub = 0;
        numMul = 0;
        numDiv = 0;
    }

    double Add(double x, double y)
    {
        numAdd++;
        return x + y;
    }

    double Sub(double x, double y)
    {
        numSub++;
        return x - y;
    }

    double Mul(double x, double y)
    {
        numMul++;
        return x * y;
    }

    double Div(double x, double y)
    {
        numDiv++;
        return x / y;
    }

    void ShowOpCount()
    {
        cout << "덧셈: " << numAdd;
        cout << " 뺄셈: " << numSub;
        cout << " 곱셈: " << numMul;
        cout << " 나눗셈: " << numDiv << endl;
    }
};

int main()
{
    Calculator cal;
    cal.Init();
    cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
    cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
    cout << "2.2 - 1.5 = " << cal.Sub(2.2, 1.5) << endl;
    cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
    cal.ShowOpCount();
    return 0;

}