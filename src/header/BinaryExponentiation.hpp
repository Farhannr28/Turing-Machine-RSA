#ifndef __BINARY_EXPONENTIATION__
#define __BINARY_EXPONENTIATION__

#include <iostream>

using namespace std;

class BinaryExponentiation {
    private:
    public:
        static BinaryExponentiation& getInstance();
        BinaryExponentiation();
        int exponent(int a, int exp, int mod);
};

#endif