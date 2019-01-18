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
    NameCard(const char *input_name, const char *input_company, const char *input_phone, const int &input_rank)
    {
        name = new char[30];
        company_name = new char[30];
        phone_num = new char[30];
        rank = input_rank;
        strcpy(name, input_name);
        strcpy(company_name, input_company);
        strcpy(phone_num, input_phone);
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
    NameCard manClerk("Lee", "ABCEng","010-1111-2222", COMP_POS::CLERK);
    NameCard manSENIOR("Hong", "OrangeEng","010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp","010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();

    return 0;
}
