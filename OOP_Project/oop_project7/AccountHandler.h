#pragma once
#include "Account.h"
#include "BankingCommonDec1.h"

class AccountHandler
{
private:
    Account *accArr[100];
    int accnum;
public:
    AccountHandler();
    void showMenu(void) const;
    void makeNormalAccount(void);
    void makeCreditAccount(void);
    void openAccount(void);
    void depositMoney(void);
    void withdrawMoney(void);
    void showAllAccInfo(void) const;
    ~AccountHandler();
};
