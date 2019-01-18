#include <iostream>
#include <cstring>

using namespace std;

class Printer
{
private:
    char s[50];

public:
    void SetString(char const *string)
    {
        strcpy(s, string);
    }

    void ShowString()
    {
        cout << s << endl;
    }
};

int main()
{
    Printer pnt;
    pnt.SetString("Hello world!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();
    return 0;
}