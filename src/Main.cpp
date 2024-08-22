#include <iostream>

#include "header/RSA.hpp"

using namespace std;

int main(){
    string temp;
    temp = RSA::getInstance().naiveEncrypt("We dont wanna see you in the presidency chair no more!");
    cout << temp << "\n";
    temp = RSA::getInstance().naiveDecrypt(temp);
    cout << temp << "\n";
    return 0;
}