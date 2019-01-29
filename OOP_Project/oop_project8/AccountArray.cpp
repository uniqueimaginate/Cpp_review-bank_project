#include "BankingCommonDec1.h"
#include "AccountArray.h"

BoundCheckPointPtrArray::BoundCheckPointPtrArray(int len) : arrlen(len)
{
    arr = new ACCOUNT_PTR[len];
}

ACCOUNT_PTR& BoundCheckPointPtrArray::operator[] (int idx)
{
    if(idx<0 || idx>=arrlen)
    {
        cout << "Array index out of bound exception" << endl;
        exit(1);
    }
    return arr[idx];
}

ACCOUNT_PTR BoundCheckPointPtrArray::operator[] (int idx) const
{
    if(idx<0 || idx>=arrlen)
    {
        cout << "Array index out of bound exception" << endl;
        exit(1);
    }
    return arr[idx];
}

int BoundCheckPointPtrArray::GetArrLen() const
{
    return arrlen;
}

BoundCheckPointPtrArray::~BoundCheckPointPtrArray()
{
    delete []arr;
}
