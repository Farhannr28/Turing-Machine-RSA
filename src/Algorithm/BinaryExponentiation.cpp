#include <iostream>

#include "../header/BinaryExponentiation.hpp"
            
using namespace std;    

BinaryExponentiation& BinaryExponentiation::getInstance(){
    static BinaryExponentiation instance;
    return instance;
}

BinaryExponentiation::BinaryExponentiation(){}

int BinaryExponentiation::exponent(int a, int exp, int mod){
    exp--;
    int res = a;
    while (exp > 0) {
        if (exp & 1){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        exp = exp >> 1;
    }
    return res % mod;
}