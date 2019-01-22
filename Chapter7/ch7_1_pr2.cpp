#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
    char * name;
    int age;
public:
    MyFriendInfo(const char * _name, int age)
        : age(age)
    {
        name = new char[strlen(_name)+1];
        strcpy(name, _name);
    }
    void ShowMyFriendInfo()
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
    ~MyFriendInfo()
    {
        delete []name;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char * addr;
    char * phone;

public:
    MyFriendDetailInfo(const char * _addr, const char * _phone, const char * _name, int age)
        : MyFriendInfo(_name, age)
    {
        addr = new char[strlen(_addr) + 1];
        phone = new char[strlen(_phone) + 1];
        strcpy(addr, _addr);
        strcpy(phone, _phone);
    }
    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout << "주소: " << addr << endl;
        cout << "전화: " << phone << endl << endl;
    }

    ~MyFriendDetailInfo()
    {
        delete []addr;
        delete []phone;
    }
};

int main()
{
    MyFriendDetailInfo frd("seoul", "010-8843-3116", "peter", 26);
    frd.ShowMyFriendDetailInfo();

    return 0;
}
