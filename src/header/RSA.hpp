#ifndef __RSA__
#define __RSA__

#include <iostream>
#include <vector>

using namespace std;

class RSA {
    private:
        const int P = 17;
        const int Q = 19;
        const int N = P * Q;
        const int D = 59;
        const int E = 83;
    public:
        RSA();
        static RSA& getInstance();
        string naiveEncrypt(string input);
        string naiveDecrypt(string input);
        vector<int> processInputEncrypt(string input);
        string processInputDecrypt(vector<int> &p);
};

#endif