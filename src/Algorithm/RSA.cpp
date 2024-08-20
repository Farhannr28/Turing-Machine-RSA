#include <iostream>
#include <sstream>
#include <vector>

#include "../header/RSA.hpp"
#include "../header/BinaryExponentiation.hpp"

using namespace std;

vector<int> getIntsFromString(const std::string& str) {
    vector<int> numbers;
    istringstream iss(str);
    int number;
    while (iss >> number) {
        numbers.push_back(number);
    }
    return numbers;
}

RSA::RSA(){}

RSA& RSA::getInstance(){
    static RSA instance;
    return instance;
}

string RSA::naiveEncrypt(string input){
    int sz = input.length();
    int p;
    int c;
    string result="";
    int i=0;
    while (i < sz){
        p = (int) input[i];
        c = BinaryExponentiation::getInstance().exponent(p, E, N);
        result = result + to_string(c) + " ";
        i++;
    }
    return result;
}

string RSA::naiveDecrypt(string input){
    vector<int> inputs = getIntsFromString(input);
    int p;
    string result="";
    for (int c : inputs){
        p = BinaryExponentiation::getInstance().exponent(c, D, N);
        result = result + (char) p;
    }
    return result;
}