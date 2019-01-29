#include "AccountHandler.h"
#include "BankingCommonDec1.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"

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
    String name;

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
    String name;

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
