#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum{CLERK, SENIOR, ASSIST, MANAGER};

    void ShowPositionInfo(int rank)
    {
        switch(rank)
        {
            case CLERK:
                cout << "사원" << endl;
                break;
            case SENIOR:
                cout << "주임" << endl;
                break;
            case ASSIST:
                cout << "대리" << endl;
                break;
            case MANAGER:
                cout << "과장" << endl;

        }
    }
}

class NameCard
{
private:
    char *name;
    char *company_name;
    char *phone_num;
    int rank;

public:
    NameCard(const char *name, const char *company_name, const char *phone_num, const int rank)
        : rank(rank)
    {
        this->name = new char[30];
        this->company_name = new char[30];
        this->phone_num = new char[30];
        strcpy(this->name, name);
        strcpy(this->company_name, company_name);
        strcpy(this->phone_num, phone_num);
    }

    NameCard(const NameCard &copy) : rank(copy.rank)
    {
        name = new char[30];
        strcpy(name, copy.name);
        company_name = new char[30];
        strcpy(company_name, copy.company_name);
        phone_num = new char[30];
        strcpy(phone_num, copy.phone_num);
    }

    void ShowNameCardInfo()
    {
        cout << "이름: " << name << endl;
        cout << "회사: " << company_name << endl;
        cout << "전화번호: " << phone_num << endl;
        cout << "직급: "; COMP_POS::ShowPositionInfo(rank);
        cout << endl;
    }

    ~NameCard()
    {
        delete []name;
        delete []company_name;
        delete []phone_num;
    }
};


int main()
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    NameCard manSENIOR("Hong", "OrangeEng","010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSENIOR;
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();

    return 0;
}
