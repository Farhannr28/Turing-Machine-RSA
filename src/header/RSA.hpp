#ifndef __RSA__
#define __RSA__

#include <iostream>
#include <vector>

#include "Emulator.hpp"
#include "RSADefiner.hpp"

using namespace std;

class RSA {
    private:
        Emulator emulator;
        RSADefiner definer;
        const int P = 5; // 3 // 23 // 17
        const int Q = 19; // 37 // 43 // 23
        const int N = P * Q; // 111 // 989 // 323
        const int D = 17; // 5 // 95 // 59
        const int E = 17; // 29 // 107 // 83
    public:
        RSA();
        static RSA& getInstance();
        string naiveEncrypt(string input);
        string naiveDecrypt(string input);
        string turingEncrypt(string input, bool print);
        string turingDecrypt(string input, bool print);
        vector<int> processInputEncrypt(string input);
        string processInputDecrypt(vector<int> &p);
};

#endif