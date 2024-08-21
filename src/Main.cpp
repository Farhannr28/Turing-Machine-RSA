#include <iostream>

#include "header/RSA.hpp"

using namespace std;

int main(){
    string temp;
    temp = RSA::getInstance().naiveEncrypt("H3LLO NeW w0RLd, aLl tHe b0yS anD g1RlS!!");
    cout << temp << "\n";
    temp = RSA::getInstance().naiveDecrypt(temp);
    cout << temp << "\n";
    return 0;
}