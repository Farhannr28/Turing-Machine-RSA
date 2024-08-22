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

vector<int> RSA::processInputEncrypt(string input){
    int p;
    int c;
    string temp = "";
    string y;
    for (char i : input){
        c = (char) i;
        y = to_string(c);
        temp += y.insert(0, 3 - y.length(), '0');
    }
    int sz = temp.length();

    vector<int> result;
    for (int i=0; i < (sz/2) * 2; i+=2){
        p = (temp[i] - '0') * 10 + (temp[i+1] - '0');
        result.push_back(p);
    }
    if (sz % 2 == 1){
        result.push_back(temp[sz-1] - '0');
    }

    return result;
}

string RSA::processInputDecrypt(vector<int> &p) {
    string temp="";
    string y;
    for (int i=0; i < (int) p.size()-1; i++){
        y = to_string(p[i]);
        temp += y.insert(0, 2 - y.length(), '0');
    }
    y = to_string(p[p.size()-1]);
    if (p.size() % 3 == 0 && p[p.size()-1] < 10){
        y.insert(0, 1, '0');
    }

    temp += y;

    vector<string> charGroups = Util::splitIntoGroupsOfThree(temp);
    string result="";
    int x;
    for (string s : charGroups){
        x = stoi(s);
        result = result + (char) x;
    }
    return result;
}

string RSA::naiveEncrypt(string input){
    string result = "";
    int c;
    string y;
    vector<int> v = processInputEncrypt(input);
    for (int p : v){
        c = BinaryExponentiation::getInstance().exponent(p, E, N);
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
    vector<int> pValues;
    for (int i=0; i < (int) groups.size(); i++){
        c = stoi(groups[i]);
        p = BinaryExponentiation::getInstance().exponent(c, D, N);
        pValues.push_back(p);
    }
    return processInputDecrypt(pValues);
}