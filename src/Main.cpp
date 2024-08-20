#include <iostream>

#include "header/RSA.hpp"

using namespace std;

int main(){
    string temp;
    temp = RSA::getInstance().naiveEncrypt("Hello, World!");
    cout << temp << "\n";
    temp = RSA::getInstance().naiveDecrypt(temp);
    cout << temp << "\n";
    return 0;
}