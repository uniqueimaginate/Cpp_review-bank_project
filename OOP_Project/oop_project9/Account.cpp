#include "Account.h"
#include "BankingCommonDec1.h"

Account::Account(int _accID, int _money, String _name)
: accID(_accID), money(_money)
{
    // name = new char[len];
    // strcpy(name, _name);
    name = _name;
}

// Account::Account(const Account &copy)
//  : accID(copy.accID), money(copy.money)
// {
//     name = new char[len];
//     strcpy(name, copy.name);
// }
//
// Account& Account::operator=(const Account &ref)
// {
//     accID = ref.accID;
//     money = ref.money;
//     delete []name;
//     name = new char[strlen(ref.name) + 1];
//     strcpy(name, ref.name);
//     return *this;
// }

int Account::getAccID(void) const
{
    return accID;
}

void Account::deposit(int num)
{
    money += num;
}

int Account::withdraw(int num)
{
    if(money < num)
        return 0;
    money -= num;
    return money;
}

void Account::showAccInfo(void) const
{
    cout << "계좌ID: " << accID << endl;
    cout << "이 름: " << name << endl;
    cout << "금 액: " << money << endl;
}

// Account::~Account()
// {
//     delete []name;
// }
