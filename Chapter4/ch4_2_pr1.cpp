#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    void Init(int x, int y)
    {
        xpos = x;
        ypos = y;
    }

    void ShowPointInfo() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

class Circle
{
private:
    Point a;
    int radius_a;

public:
    void Init(const int &x, const int &y, const int &rad)
    {
        a.Init(x,y);
        radius_a = rad;
    }
    void ShowCircleInfo() const
    {
        cout << "radius: " << radius_a << endl;
        a.ShowPointInfo();
    }
};

class Ring
{
private:
    Circle a;
    Circle b;

public:
    void Init(  const int &x1, const int &y1, 
                const int &rad1, const int &x2, 
                const int &y2, const int &rad2)
    {
        a.Init(x1,y1,rad1);
        b.Init(x2,y2,rad2);
    }
    void ShowRingInfo() const
    {
        cout << "Inner Circle Info..." << endl;
        a.ShowCircleInfo();
        cout << "Outer Circle Info..." << endl;
        b.ShowCircleInfo();
    }
};

int main(void)
{
    Ring ring;
    ring.Init(1,1,4,2,2,9);
    ring.ShowRingInfo();
    return 0;
}