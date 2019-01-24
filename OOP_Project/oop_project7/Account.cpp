#include "Account.h"
#include "BankingCommonDec1.h"

Account::Account(int _accID, int _money, char * _name)
: accID(_accID), money(_money)
{
    name = new char[len];
    strcpy(name, _name);
}

Account::Account(const Account &copy)
 : accID(copy.accID), money(copy.money)
{
    name = new char[len];
    strcpy(name, copy.name);
}

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

Account::~Account()
{
    delete []name;
}
