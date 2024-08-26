#include <iostream>

#include "header/RSA.hpp"

using namespace std;

int main(){
    string naive;
    string turing;
    string INPUT = "abc";
    cout << "NAIVE: " << "\n";
    naive = RSA::getInstance().naiveEncrypt(INPUT);
    cout << naive << "\n";
    naive = RSA::getInstance().naiveDecrypt(naive);
    cout << naive << "\n";
    cout << "\n";
    cout << "TURING: " << "\n";
    turing = RSA::getInstance().turingEncrypt(INPUT);
    cout << turing << "\n";
    turing = RSA::getInstance().turingDecrypt(turing);
    cout << turing << "\n";
    return 0;
}