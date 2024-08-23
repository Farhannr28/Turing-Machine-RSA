#include "../header/RSADefiner.hpp"
#include "../header/Definition.hpp"
#include "../header/State.hpp"
#include "../header/Transition.hpp"

using namespace std;

RSADefiner::RSADefiner(int p, int q, int d, int e) : P(p), Q(q), D(d), E(e) {}

RSADefiner::~RSADefiner(){}

vector<int> RSADefiner::readTapeResult(vector<char>& tape) {
    int sz = tape.size();
    int i=0;
    while (tape[i] != '1' && i < sz){
        i++;
    }
    int count;
    vector<int> ret;
    while (i < sz){
        count = 0;
        while (tape[i] == '1' && i < sz){
            count++;
            i++;
        }
        ret.push_back(count);
        i++;
    }
    return ret;
}

vector<char>& RSADefiner::createInitialTape(vector<int>& num, bool isEncrypt) {
    vector<char> ret;
    ret.push_back('R');
    for (int n : num){
        for (int i=0;i<n;i++){
            ret.push_back('1');
        }
        ret.push_back('Z');
    }
    ret.push_back('Y');
    if (isEncrypt){
        for (int i=0; i<this->E; i++){
            ret.push_back('1');
        }
    } else {
        for (int i=0; i<this->D; i++){
            ret.push_back('1');
        }
    }
    ret.push_back('X');
    int N = this->P * this->Q;
    for (int i=0; i< N; i++){
        ret.push_back('1');
    }
    ret.push_back('W');
    for (int i=0; i< N; i++){
        ret.push_back('B');
    }
    ret.push_back('U');
    ret.push_back('T');
    return ret;
}

void RSADefiner::define(Definition& d) {
    d.setStartState(0);

    // Main Loop
    State q0;
    q0.addTransition('R', 0, 'R', true);
    q0.addTransition('1', 1, 'V', true);
    q0.addTransition('Z', 3, 'V', true);
    q0.addTransition('Y', 38, 'B', true);
    State q1;
    q1.addTransition('B', 2, '1', false);
    q1.addTransition('1', 1, '1', true);
    q1.addTransition('Z', 1, 'Z', true);
    q1.addTransition('Y', 1, 'Y', true);
    q1.addTransition('X', 1, 'X', true);
    q1.addTransition('W', 1, 'W', true);
    State q2;
    q2.addTransition('V', 0, 'V', true);
    q2.addTransition('1', 2, '1', false);
    q2.addTransition('Z', 2, 'Z', false);
    q2.addTransition('Y', 2, 'Y', false);
    q2.addTransition('X', 2, 'X', false);
    q2.addTransition('W', 2, 'W', false);
    State q3;
    q3.addTransition('T', 4, 'T', true);
    q3.addTransition('1', 3, '1', true);
    q3.addTransition('W', 3, 'W', true);
    q3.addTransition('X', 3, 'X', true);
    q3.addTransition('Y', 3, 'Y', true);
    q3.addTransition('Z', 3, 'Z', true);
    q3.addTransition('B', 3, 'B', true);
    q3.addTransition('U', 3, 'U', true);
    State q4;
    q4.addTransition('B', 5, '1', false);
    State q5;
    q5.addTransition('Y', 6, 'Y', true);
    q5.addTransition('U', 5, 'U', false);
    q5.addTransition('B', 5, 'B', false);
    q5.addTransition('1', 5, '1', false);
    q5.addTransition('W', 5, 'W', false);
    q5.addTransition('X', 5, 'X', false);
    State q33;
    q33.addTransition('W', 34, 'W', true);
    q33.addTransition('1', 33, '1', true);
    q33.addTransition('X', 33, 'X', true);
    State q34;
    q34.addTransition('U', 35, 'U', true);
    q34.addTransition('1', 34, 'B', true);
    State q35;
    q35.addTransition('T', 36, 'B', true);
    q35.addTransition('1', 35, '1', true);
    q35.addTransition('B', 35, 'B', true);
    State q36;
    q36.addTransition('B', 37, 'T', false);
    q36.addTransition('1', 36, '1', true);
    State q37;
    q37.addTransition('V', 0, 'V', true);
    q37.addTransition('1', 37, '1', false);
    q37.addTransition('B', 37, 'B', false);
    q37.addTransition('U', 37, 'U', false);
    q37.addTransition('W', 37, 'W', false);
    q37.addTransition('X', 37, 'X', false);
    q37.addTransition('Y', 37, 'Y', false);
    q37.addTransition('Z', 37, 'Z', false);
    State q38;
    q38.addTransition('U', 39, 'B', false);
    q38.addTransition('1', 38, 'B', true);
    q38.addTransition('X', 38, 'B', true);
    q38.addTransition('Y', 38, 'B', true);
    q38.addTransition('B', 38, 'B', true);
    State q39;
    q39.addTransition('B', 39, 'B', false);
    q39.addTransition('V', 39, 'B', false);
    // Meet R and Halts

    d.addState(q0);
    d.addState(q1);
    d.addState(q2);
    d.addState(q3);
    d.addState(q4);
    d.addState(q5);
    d.addState(q33);
    d.addState(q34);
    d.addState(q35);
    d.addState(q36);
    d.addState(q37);
    d.addState(q38);
    d.addState(q39);

    // Exponent
    State q6;
    q6.addTransition('X', 32, 'X', false);
    q6.addTransition('1', 7, '0', true);
    q6.addTransition('0', 6, '0', true);
    State q31;
    q31.addTransition('Y', 6, 'Y', true);
    q31.addTransition('1', 31, '1', false);
    q31.addTransition('0', 31, '0', false);
    State q32;
    q32.addTransition('Y', 33, 'Y', true);
    q32.addTransition('0', 32, '1', false);
    
    d.addState(q6);
    d.addState(q31);
    d.addState(q32);

    // Multiplication
    State q7;
    q7.addTransition('T', 8, 'T', true);
    q7.addTransition('1', 7, '1', true);
    q7.addTransition('X', 7, 'X', true);
    q7.addTransition('W', 7, 'W', true);
    q7.addTransition('B', 7, 'B', true);
    q7.addTransition('U', 7, 'U', true);
    State q8;
    q8.addTransition('B', 9, 'S', false);
    q8.addTransition('1', 8, '1', true);
    State q9;
    q9.addTransition('T', 10, 'T', false);
    q9.addTransition('1', 9, '1', false);
    State q10;
    q10.addTransition('1', 11, '0', false);
    q10.addTransition('U', 10, 'U', false);
    q10.addTransition('B', 10, 'B', false);
    State q11;
    q11.addTransition('W', 17, 'W', true);
    q11.addTransition('1', 12, '0', true);
    q11.addTransition('0', 11, '0', false);
    q11.addTransition('U', 11, 'U', false);
    q11.addTransition('B', 11, 'B', false);
    State q12;
    q12.addTransition('T', 13, 'T', true);
    q12.addTransition('0', 12, '0', true);
    q12.addTransition('B', 12, 'B', true);
    q12.addTransition('U', 12, 'U', true);
    State q13;
    q13.addTransition('1', 14, '0', true);
    q13.addTransition('0', 13, '0', true);
    q13.addTransition('S', 16, 'S', false);
    State q14;
    q14.addTransition('B', 15, '1', false);
    q14.addTransition('1', 14, '1', true);
    q14.addTransition('S', 14, 'S', true);
    State q15;
    q15.addTransition('0', 13, '0', true);
    q15.addTransition('1', 15, '1', false);
    q15.addTransition('S', 15, 'S', false);
    State q16;
    q16.addTransition('T', 11, 'T', false);
    q16.addTransition('0', 16, '1', false);
    State q17;
    q17.addTransition('S', 18, 'S', true);
    q17.addTransition('0', 17, '1', true);
    q17.addTransition('B', 17, 'B', true);
    q17.addTransition('U', 17, 'U', true);
    q17.addTransition('T', 17, 'T', true);
    q17.addTransition('1', 17, '1', true);
    State q18;
    q18.addTransition('B', 19, 'B', false);
    State q19;
    q19.addTransition('1', 20, 'B', false);
    State q20;
    q20.addTransition('S', 21, '1', false);
    q20.addTransition('1', 20, '1', false);

    d.addState(q7);
    d.addState(q8);
    d.addState(q9);
    d.addState(q10);
    d.addState(q11);
    d.addState(q12);
    d.addState(q13);
    d.addState(q14);
    d.addState(q15);
    d.addState(q16);
    d.addState(q17);
    d.addState(q18);
    d.addState(q19);
    d.addState(q20);

    // Modulo
    State q21;
    q21.addTransition('X', 22, 'X', true);
    q21.addTransition('1', 21, '1', false);
    q21.addTransition('T', 21, 'T', false);
    q21.addTransition('U', 21, 'U', false);
    q21.addTransition('B', 21, 'B', false);
    q21.addTransition('W', 21, 'W', false);
    q21.addTransition('0', 21, '0', false);
    State q22;
    q22.addTransition('W', 26, 'W', true);
    q22.addTransition('1', 23, '0', true);
    q22.addTransition('0', 22, '0', true);
    State q23;
    q23.addTransition('T', 24, 'T', true);
    q23.addTransition('W', 23, 'W', true);
    q23.addTransition('1', 23, '1', true);
    q23.addTransition('B', 23, 'B', true);
    q23.addTransition('U', 23, 'U', true);
    State q24;
    q24.addTransition('B', 25, 'B', false);
    q24.addTransition('1', 24, '1', true);
    q24.addTransition('0', 24, '0', true);
    State q25;
    q25.addTransition('1', 21, '1', false);
    q25.addTransition('0', 25, '0', false);
    q25.addTransition('T', 29, 'T', true);
    State q26;
    q26.addTransition('T', 27, 'T', true);
    q26.addTransition('1', 26, '1', true);
    q26.addTransition('B', 26, 'B', true);
    q26.addTransition('U', 26, 'U', true);
    State q27;
    q27.addTransition('B', 28, 'B', false);
    q27.addTransition('0', 27, 'B', true);
    q27.addTransition('1', 27, '1', true);
    State q28;
    q28.addTransition('X', 22, 'X', true);
    q28.addTransition('0', 28, '1', false);
    q28.addTransition('1', 28, '1', false);
    q28.addTransition('T', 28, 'T', false);
    q28.addTransition('U', 28, 'U', false);
    q28.addTransition('B', 28, 'B', false);
    q28.addTransition('W', 28, 'W', false);
    State q29;
    q29.addTransition('B', 30, 'B', false);
    q29.addTransition('0', 29, '1', true);
    State q30;
    q30.addTransition('X', 31, 'X', false);
    q30.addTransition('0', 30, '1', false);
    q30.addTransition('T', 30, 'T', false);
    q30.addTransition('U', 30, 'U', false);
    q30.addTransition('B', 30, 'B', false);
    q30.addTransition('1', 30, '1', false);
    q30.addTransition('W', 30, 'W', false);

    d.addState(q21);
    d.addState(q22);
    d.addState(q23);
    d.addState(q24);
    d.addState(q25);
    d.addState(q26);
    d.addState(q27);
    d.addState(q28);
    d.addState(q29);
    d.addState(q30);
}