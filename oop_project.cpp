#include <iostream>
#include <cstring>

using namespace std;
const int len = 20;

void showMenu(void);
void openAccount(void);
void depositMoney(void);
void withdrawMoney(void);
void showAllAccInfo(void);

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};


typedef struct {
    int accID;
    int money;
    char name[len];
} Account;

Account accArr[100];
int accnum = 0;

int main(void)
{
    int choice;

    while(1)
    {
        showMenu();
        cout << "선택 : ";
        cin >> choice;
        cout << endl;

        switch(choice)
        {
        case MAKE:
            openAccount();
            break;
        case DEPOSIT:
            depositMoney();
            break;
        case WITHDRAW:
            withdrawMoney();
            break;
        case INQUIRE:
            showAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }

    return 0;
}

void showMenu(void)
{
    cout<<"-----Menu-----"<<endl;
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입 금"<<endl;
    cout<<"3. 출 금"<<endl;
    cout<<"4. 계좌정보 전체 출력"<<endl;
    cout<<"5. 프로그램 종료"<<endl;
}

void openAccount(void)
{
    int id;
    char name[len];
    int balance;

    cout<<"[계좌개설]"<<endl;
    cout<<"계좌ID : ";
    cin>>id;
    cout<<"이 름 : ";
    cin>>name;
    cout<<"입금액 : ";
    cin>>balance;
    cout<<endl;

    accArr[accnum].accID = id;
    accArr[accnum].money = balance;
    strcpy(accArr[accnum].name, name);
    accnum++;
}

void depositMoney(void)
{
    int money;
    int id;
    cout<<"[입 금]"<<endl;
    cout<<"계좌ID : ";
    cin>>id;
    cout<<"입금액 : ";
    cin>>money;

    for(int i = 0; i<accnum; i++)
    {
        if(accArr[i].accID == id)
        {
            accArr[i].money += money;
            cout<<"입금완료"<<endl;
            return;
        }
    }
    cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
    
}

void withdrawMoney()
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
        if(accArr[i].accID == id)
        {
            if(accArr[i].money < money)
            {
                cout<<"잔액부족"<<endl;
                return;
            }
            accArr[i].money -= money;
            cout<<"출금완료"<<endl<<endl;
            return;
        }
    }

    cout<<"유효하지 않은 ID입니다."<<endl<<endl;
}

void showAllAccInfo(void)
{
    for(int i = 0; i<accnum; i++)
    {
        cout<<accArr[i].accID<<endl;
        cout<<accArr[i].name<<endl;
        cout<<accArr[i].money<<endl;
    }
}