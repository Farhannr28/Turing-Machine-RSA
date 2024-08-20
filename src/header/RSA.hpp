#ifndef __RSA__
#define __RSA__

#include <iostream>

using namespace std;

class RSA {
    private:
        const int P = 17;
        const int Q = 19;
        const int N = P * Q;
        const int D = 173;
        const int E = 5;
    public:
        RSA();
        static RSA& getInstance();
        string naiveEncrypt(string input);
        string naiveDecrypt(string input);
};

#endif