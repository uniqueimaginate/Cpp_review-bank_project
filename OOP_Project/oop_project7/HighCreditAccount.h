#pragma once

#include "NormalAccount.h"
class HighCreditAccount : public NormalAccount
{
private:
    int creditRank;
public:
    HighCreditAccount(int _id, int _balance, char * _name, int _interest, int _credit)
        : NormalAccount(_id, _balance, _name, _interest), creditRank(_credit)
    {}


    virtual void deposit(int money)
    {
        NormalAccount::deposit(money);
        Account::deposit(money*(creditRank/100.0));
    }
};
