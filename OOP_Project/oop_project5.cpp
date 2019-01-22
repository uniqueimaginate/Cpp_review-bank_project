#include <iostream>
#include <cstring>

using namespace std;
const int len = 20;

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account
{
private:
    int accID;
    int money;
    char *name;

public:
    Account(int _accID, int _money, char * _name);
    Account(const Account &copy);

    int getAccID(void) const;
    void deposit(int num);
    int withdraw(int num);
    void showAccInfo(void) const;
    ~Account();
};

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


class AccountHandler
{
private:
    Account *accArr[100];
    int accnum;
public:
    AccountHandler();
    void showMenu(void) const;
    void openAccount(void);
    void depositMoney(void);
    void withdrawMoney(void);
    void showAllAccInfo(void) const;
    ~AccountHandler();
};

AccountHandler::AccountHandler() : accnum(0)
{}

void AccountHandler::showMenu(void) const
{
    cout<<"-----Menu-----"<<endl;
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입 금"<<endl;
    cout<<"3. 출 금"<<endl;
    cout<<"4. 계좌정보 전체 출력"<<endl;
    cout<<"5. 프로그램 종료"<<endl;
}

void AccountHandler::openAccount(void)
{
    int id;
    int balance;
    char name[len];

    cout << "[계좌개설]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "이름: "; cin>>name;
    cout << "입금액: "; cin >> balance;
    cout << endl;

    accArr[accnum++] = new Account(id, balance, name);
}

void AccountHandler::depositMoney(void)
{
    int money;
    int id;
    cout << "[입 금]" << endl;
    cout << "계좌ID : "; cin>>id;
    cout << "입금액 : ";  cin>>money;

    for(int i = 0; i<accnum; i++)
    {
        if(accArr[i] -> getAccID() == id)
        {
            accArr[i] -> deposit(money);
            cout<<"입금완료"<<endl;
            return;
        }
    }
    cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
}

void AccountHandler::withdrawMoney(void)
{
    int money;
    int id;
    cout<<"[출 금]"<<endl;
    cout<<"계좌ID : ";
    cin>>id;
    cout<<"출금액 : ";
    cin>>money;

    for(int i = 0; i<accnum; i++)
    {
        if(accArr[i] -> getAccID() == id)
        {
            if(accArr[i] -> withdraw(money) == 0)
            {
                cout<<"잔액부족"<<endl;
                return;
            }

            cout<<"출금완료"<<endl<<endl;
            return;
        }
    }

    cout<<"유효하지 않은 ID입니다."<<endl<<endl;
}

void AccountHandler::showAllAccInfo(void) const
{
    for(int i = 0; i<accnum; i++)
    {
        accArr[i] -> showAccInfo();
        cout << endl;
    }
}

AccountHandler::~AccountHandler(void)
{
    for(int i = 0 ; i < accnum; i++)
    {
        delete accArr[i];
    }
}

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
