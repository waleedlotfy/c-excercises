#include "complex.h"
#include <cmath>
#include <iostream>

bool digit_is_comming(std::istream& s);

std::ostream& operator<<(std::ostream& s, const Complex& rhs)
{
    if (rhs.mR == 0.0) {
        if (rhs.mI > 0.0)
            s << "i" << std::fabs(rhs.mI);
        else if (rhs.mI < 0.0)
            s << "-i" << std::fabs(rhs.mI);
        else
            s << rhs.mR;
    }
    else {
        s << rhs.mR;
        if (rhs.mI > 0.0)
            s << "+i" << std::fabs(rhs.mI);
        else if (rhs.mI < 0.0)
            s << "-i" << std::fabs(rhs.mI);
     }

    return s;
}

std::istream& operator>>(std::istream& s, Complex& rhs)
{
    bool isPositive = true;
    bool isImaginary = false;
    double modulus = 0.0;

    if ('_' == s.peek()) {
        s.ignore(1);
        isPositive = false;
    }

    if ('i' == s.peek()) {
        s.ignore(1);
        isImaginary = true;
        modulus = 1.0;
    }

    if ('0' <= s.peek() && s.peek() <= '9')
        s >> modulus;

    if (isImaginary)
        rhs.mI = isPositive ? modulus : -modulus;
    else
        rhs.mR = isPositive ? modulus : -modulus;

    return s;
}
