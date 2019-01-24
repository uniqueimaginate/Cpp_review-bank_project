#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    {}

    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }

    Point& operator++()
    {
        xpos+=1;
        ypos+=1;
        return *this;
    }

    Point& operator-()
    {
        xpos = -xpos;
        ypos = -ypos;
        return *this;
    }

    friend Point& operator~(const Point &ref);
};

Point& operator~(Point &ref)
{
    int temp = ref.xpos;
    ref.xpos = ref.ypos;
    ref.ypos = temp;
    return ref;
}

int main()
{
    Point pos1(1,3);
    Point pos2(5,7);

    -pos2;
    pos2.ShowPosition();
    return 0;
}