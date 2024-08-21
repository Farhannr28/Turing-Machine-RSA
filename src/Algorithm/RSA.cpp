#include <iostream>
#include <sstream>
#include <vector>

#include "../header/RSA.hpp"
#include "../header/BinaryExponentiation.hpp"
#include "../header/Util.hpp"

using namespace std;

RSA::RSA(){}

RSA& RSA::getInstance(){
    static RSA instance;
    return instance;
}

string RSA::naiveEncrypt(string input){
    int p;
    int c;
    string temp = "";
    int x;
    string y;
    for (char i : input){
        x = (char) i;
        y = to_string(x);
        temp += y.insert(0, 3 - y.length(), '0');
    }
    int sz = temp.length();
    string result = "";
    for (int i=0; i < (sz/2 * 2); i+=2){
        p = (temp[i] - '0') * 10 + (temp[i+1] - '0');
        c = BinaryExponentiation::getInstance().exponent(p, E, N);
        y = to_string(c);
        result = result + y.insert(0, 3 - y.length(), '0');
    }
    if (sz % 2 == 1){
        c = BinaryExponentiation::getInstance().exponent(temp[sz-1] - '0', E, N);
        y = to_string(c);
        result = result + y.insert(0, 3 - y.length(), '0');
    }
    return result;
}

string RSA::naiveDecrypt(string input){
    vector<string> groups = Util::splitIntoGroupsOfThree(input);
    int c;
    int p;
    string temp="";
    string y;
    for (int i=0; i < (int) groups.size()-1; i++){
        c = stoi(groups[i]);
        p = BinaryExponentiation::getInstance().exponent(c, D, N);
        y = to_string(p);
        temp += y.insert(0, 2 - y.length(), '0');
    }
    c = stoi(groups[groups.size()-1]);
    p = BinaryExponentiation::getInstance().exponent(c, D, N);
    y = to_string(p);
    if (groups.size() % 3 == 0){
        y.insert(0, 1, '0');
    }
    temp += y;
    vector<string> charGroups = Util::splitIntoGroupsOfThree(temp);
    string result="";
    for (string s : charGroups){
        p = stoi(s);
        result = result + (char) p;
    }
    return result;
}