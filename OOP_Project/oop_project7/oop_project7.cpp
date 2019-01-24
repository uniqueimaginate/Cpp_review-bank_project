#include <iostream>
#include <cstring>

using namespace std;
const int len = 20;

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
enum {A = 7, B = 4, C = 1};
enum {NORMAL = 1, CREDIT = 2};

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
    virtual void deposit(int num);
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


class NormalAccount : public Account
{
private:
    int interest;
public:
    NormalAccount(int _id, int _balance, char * _name, int _interest)
     : Account(_id, _balance, _name), interest(_interest)
    {}

    virtual void deposit(int money)
    {
        Account::deposit(money);
        Account::deposit(money*(interest/100.0));
    }
};

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
    int choice;
    cout << "[계좌종류선택]" << endl;
    cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
    cout << "선택: ";
    cin >> choice;

    if(choice == NORMAL)
        makeNormalAccount();
    else
        makeCreditAccount();
    switch(choice)
    {
        case NORMAL:

            break;
        case CREDIT:

            break;
    }
}

void AccountHandler::makeNormalAccount(void)
{
    int id;
    int balance;
    int interest;
    char name[len];

    cout << "[보통예금계좌 개설]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "이름: "; cin >> name;
    cout << "입금액: "; cin >> balance;
    cout << "이자율: "; cin >> interest;
    cout << endl;
    accArr[accnum++] = new NormalAccount(id, balance, name, interest);
}

void AccountHandler::makeCreditAccount(void)
{
    int id;
    int balance;
    int interest;
    int credit;
    char name[len];

    cout << "[신용예금계좌 개설]" << endl;
    cout << "계좌ID: "; cin >> id;
    cout << "이름: "; cin >> name;
    cout << "입금액: "; cin >> balance;
    cout << "이자율: "; cin >> interest;
    cout << "신용등급(1toA, 2toB, 3toC): "; cin >> credit;
    cout << endl;

    switch(credit)
    {
    case 1:
        accArr[accnum++] = new HighCreditAccount(id, balance, name, interest, A);
        break;
    case 2:
        accArr[accnum++] = new HighCreditAccount(id, balance, name, interest, B);
        break;
    case 3:
        accArr[accnum++] = new HighCreditAccount(id, balance, name, interest, C);
    }

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
