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

string RSA::turingEncrypt(string input, bool print){
    vector<int> v = processInputEncrypt(input);
    int c;
    string y;
    string result = "";
    int p;
    int sz = v.size();
    for (int i=0; i<sz; i++) {
        p = v[i];
        vector<char> t = definer.createInitialTape(p);
        this->emulator.setInitialTape(t);
        if (this->emulator.run(print, i, sz)){
            c = this->definer.readTapeResult(this->emulator.getTape());
            y = to_string(c);
            result = result + y.insert(0, 2 - y.length(), '0');
        } else {
            return "Error running Turing Machine";
        }
    }
    return result;
}

string RSA::turingDecrypt(string input, bool print){
    vector<string> groups = Util::splitIntoGroupsOfTwo(input);
    vector<int> pValues;
    int c;
    vector<char> t;
    string g;
    int sz = groups.size();
    for (int i=0; i<sz; i++){
        g = groups[i];
        c = stoi(g);
        t = definer.createInitialTape(c);
        this->emulator.setInitialTape(t);
        if (this->emulator.run(print, i, sz)){
            pValues.push_back(this->definer.readTapeResult(this->emulator.getTape()));
        } else {
            return "Error running Turing Machine";
        }
    }
    return processInputDecrypt(pValues);
}