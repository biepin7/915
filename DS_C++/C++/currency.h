// currency class using three data members
// (sign, dollars, and cents) to
// represent an instance/object

#ifndef currency_
#define currency_

#include <iostream>
#include "myExceptions.h"

using namespace std;

// plus : 美元 minus 美分
enum signType
{
    plus,
    minus
};

class currency
{
private:
    signType sign;
    unsigned long dollars;
    unsigned int cents;

public:
    // 构造函数
    currency(signType theSign = plus, unsigned long theDollars = 0, unsigned int theCents = 0);
    ~currency();

    // 可以不写形参名
    void setValue(signType, unsigned long, unsigned int);
    void setValue(double);

    // 三个常量函数
    signType getSign() const { return sign; };
    unsigned long getDollars() const { return dollars; };
    unsigned int getCents() const { return cents; };

    currency add(const currency &) const;
    currency &increment(const currency &);

    viod output() const;
};

// 在外面整函数，需要作用域
currency::currency(signType theSign, unsigned long theDollars,
                   unsigned int theCents)
{
    setValue(theSign, theDollars, theCents);
}

void currency::setValue(signType theSign, unsigned long theDollars,
                        unsigned int theCents)
{
    if (theCents > 99)
        throw illegalParameterValue("Cents should be < 100");

    sign = theSign;
    dollars = theDollars;
    cents = theCents;
}

void currency::setValue(double theAmount)
{
    if (theAmount < 0)
    {
        sign = minus;
        theAmount = -theAmount;
    }
    else
        sign = plus;

    dollars = (unsigned long)theAmount;

    cents = (unsigned int)((theAmount + 0.001 - dollars) * 100);
}

currency currency::add(const currency &x) const
{
    long a1, a2, a3;
    currency result;

    a1 = dollars * 100 + cents;
    if (sign == minus)
        a1 = -a1;

    a2 = x.dollars * 100 + x.cents;
    if (x.sign == minus)
        a2 = -a2;

    a3 = a1 + a2;

    if (a3 < 0)
    {
        result.sign = minus;
        a3 = -a3;
    }
    else
        result.sign = plus;
    result.dollars = a3 / 100;
    result.cents = a3 - result.dollars * 100;

    return result;
}

currency &currency::increment(const currency &x)
{
    *this = add(x);
    return *this;
}

void currency::output() const
{
    if (sign == minus)
        cout << '-';
    cout << '$' << dollars << '.';
    if (cents < 10)
        cout << '0';
    cout << cents;
}

#endif
