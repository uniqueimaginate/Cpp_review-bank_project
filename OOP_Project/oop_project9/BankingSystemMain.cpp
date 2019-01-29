#include "BankingCommonDec1.h"
#include "AccountHandler.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"

int main(void)
{
    AccountHandler manager;
    int choice;

    while(1)
    {
        manager.showMenu();
        cout << "선택 : ";
        cin >> choice;
        cout << endl;

        switch(choice)
        {
        case MAKE:
            manager.openAccount();
            break;
        case DEPOSIT:
            manager.depositMoney();
            break;
        case WITHDRAW:
            manager.withdrawMoney();
            break;
        case INQUIRE:
            manager.showAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}
