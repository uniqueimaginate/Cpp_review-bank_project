#pragma once

class MinusException{
private:
    int exval;
public:
    MinusException(int val) : exval(val)
    {}

    void showExceptionInfo(void) const
    {
        cout << "입(출)금액 " << exval << "유효하지 않습니다!" << endl;
    }
};

class InsuffException{
private:
    int balance;
    int reqval;

public:
    InsuffException(int val, int req)
        : balance(val), reqval(req)
    {}

    void showExceptionInfo(void) const
    {
        cout << "잔액에서 "<< reqval-balance<< "가(이) 부족합니다!" << endl;
    }
};
