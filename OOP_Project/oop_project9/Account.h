#pragma once
#include "string.h"
class Account
{
private:
    int accID;
    int money;
    String name;

public:
    Account(int _accID, int _money, String _name);
    // Account(const Account &copy);
    // Account& operator=(const Account &ref);

    int getAccID(void) const;
    virtual void deposit(int num);
    int withdraw(int num);
    void showAccInfo(void) const;
    // ~Account();
};
