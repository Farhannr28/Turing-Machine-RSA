#include <iostream>
#include <sstream>
#include <vector>

#include "../header/RSA.hpp"
#include "../header/RSADefiner.hpp"
#include "../header/BinaryExponentiation.hpp"
#include "../header/Util.hpp"

using namespace std;

RSA::RSA() {
    this->definer.setP(this->P);
    this->definer.setQ(this->Q);
    this->definer.setD(this->D);
    this->definer.setE(this->E);
    this->definer.define(this->emulator.getDefinition());
}

RSA& RSA::getInstance(){
    static RSA instance;
    return instance;
}

// vector<int> RSA::processInputEncrypt(string input){
//     int p;
//     int c;
//     string temp = "";
//     string y;
//     for (char i : input){
//         c = (char) i;
//         y = to_string(c);
//         temp += y.insert(0, 3 - y.length(), '0');
//     }
//     int sz = temp.length();

//     vector<int> result;
//     for (int i=0; i < (sz/2) * 2; i+=2){
//         p = (temp[i] - '0') * 10 + (temp[i+1] - '0');
//         result.push_back(p);
//     }
//     if (sz % 2 == 1){
//         result.push_back(temp[sz-1] - '0');
//     }

//     return result;
// }

// string RSA::processInputDecrypt(vector<int> &p) {
//     string temp="";
//     string y;
//     for (int i=0; i < (int) p.size()-1; i++){
//         y = to_string(p[i]);
//         temp += y.insert(0, 2 - y.length(), '0');
//     }
//     y = to_string(p[p.size()-1]);
//     if (p.size() % 3 == 0 && p[p.size()-1] < 10){
//         y.insert(0, 1, '0');
//     }

//     temp += y;

//     vector<string> charGroups = Util::splitIntoGroupsOfThree(temp);
//     string result="";
//     int x;
//     for (string s : charGroups){
//         x = stoi(s);
//         result = result + (char) x;
//     }
//     return result;
// }

vector<int> RSA::processInputEncrypt(string input){
    int c;
    string temp = "";
    string y;
    vector<int> result;
    for (char i : input){
        c = (char) i - 31;
        result.push_back(c);
    }
    return result;
}

string RSA::processInputDecrypt(vector<int> &p) {
    string result = "";
    for (int x : p){
        x += 31;
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
        result = result + y.insert(0, 2 - y.length(), '0');
    }
    return result;
}

string RSA::naiveDecrypt(string input){
    vector<string> groups = Util::splitIntoGroupsOfTwo(input);
    int c;
    int p;
    vector<int> pValues;
    for (int i=0; i < (int) groups.size(); i++){
        c = stoi(groups[i]);
        p = BinaryExponentiation::getInstance().exponent(c, D, N);
        pValues.push_back(p);
    }
    return processInputDecrypt(pValues);
}

string RSA::turingEncrypt(string input){
    vector<int> v = processInputEncrypt(input);
    int c;
    string y;
    string result = "";
    for (int p : v) {
        vector<char> t = definer.createInitialTape(p);
        this->emulator.setInitialTape(t);
        if (this->emulator.run()){
            c = this->definer.readTapeResult(this->emulator.getTape());
            y = to_string(c);
            result = result + y.insert(0, 2 - y.length(), '0');
        } else {
            return "Error running Turing Machine";
        }
    }
    return result;
}

string RSA::turingDecrypt(string input){
    vector<string> groups = Util::splitIntoGroupsOfTwo(input);
    vector<int> pValues;
    int c;
    vector<char> t;
    for (string g : groups){
        c = stoi(g);
        t = definer.createInitialTape(c);
        this->emulator.setInitialTape(t);
        if (this->emulator.run()){
            pValues.push_back(this->definer.readTapeResult(this->emulator.getTape()));
        } else {
            return "Error running Turing Machine";
        }
    }
    return processInputDecrypt(pValues);
}