#pragma once

class Account
{
private:
    int accID;
    int money;
    char *name;

public:
    Account(int _accID, int _money, char * _name);
    Account(const Account &copy);
    Account& operator=(const Account &ref);

    int getAccID(void) const;
    virtual void deposit(int num);
    int withdraw(int num);
    void showAccInfo(void) const;
    ~Account();
};
