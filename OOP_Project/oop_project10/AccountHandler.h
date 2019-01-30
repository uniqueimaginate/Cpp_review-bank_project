#pragma once
#include "Account.h"
#include "BankingCommonDec1.h"
#include "BoundCheckArray.h"
#include "string.h"

class AccountHandler
{
private:
    BoundCheckArray<Account*> accArr;
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
