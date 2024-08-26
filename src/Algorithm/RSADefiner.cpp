#include <iostream>

#include "../header/RSADefiner.hpp"
#include "../header/Definition.hpp"
#include "../header/State.hpp"
#include "../header/Transition.hpp"

using namespace std;

RSADefiner::RSADefiner() {}

RSADefiner::~RSADefiner() {}

void RSADefiner::setP(int x){
    this->P = x;
}

void RSADefiner::setQ(int x){
    this->Q = x;
}

void RSADefiner::setD(int x){
    this->D = x;
}

void RSADefiner::setE(int x){
    this->E = x;
}

/* BINARY VERSION */
vector<char> RSADefiner::createInitialTape(int num) {
    vector<char> ret;
    ret.push_back('Y');
    ret.push_back('1');
    ret.push_back('0');
    ret.push_back('0');
    ret.push_back('0');
    ret.push_back('1');
    ret.push_back('X');
    ret.push_back('B');
    ret.push_back('B');
    ret.push_back('B');
    ret.push_back('B');
    ret.push_back('B');
    ret.push_back('B');
    ret.push_back('B');
    ret.push_back('1');
    ret.push_back('0');
    ret.push_back('1');
    ret.push_back('1');
    ret.push_back('1');
    ret.push_back('1');
    ret.push_back('1');
    ret.push_back('W');
    for (int i=0; i<14; i++){
        ret.push_back('0');
    }
    ret.push_back('U');
    for (int i=0; i<14; i++){
        ret.push_back('0');
    }
    ret.push_back('T');
    for (int i=0; i<7; i++){
        ret.push_back('B');
    }
    int i = 64;
    while (i > 0){
        if (num & i){
            ret.push_back('1');
        } else {
            ret.push_back('0');
        }
        i >>= 1;
    }
    ret.push_back('Z');
    for (int i=0; i<13; i++){
        ret.push_back('B');
    }
    ret.push_back('1');
    ret.push_back('S');
    return ret;
}

int RSADefiner::readTapeResult(vector<char>& tape) {
    int i = 0;
    int ret = 0;
    while (tape[i] != 'U'){
        i++;
    }
    i++;
    int j = 8192;
    while (j > 0){
        if (tape[i] == '1'){
            ret += j;
        }
        i++;
        j >>= 1;
    }
    // ret %= (P * Q);
    return ret;
}

void RSADefiner::define(Definition& d) {
    d.setStartState(0);

    /* BINARY VERSION */
    State q0;
    State q1;
    State q2;
    State q3;
    State q4;
    State q5;
    State q6;
    State q7;
    State q8;
    State q9;
    State q10;
    State q11;
    State q12;
    State q13;
    State q14;
    State q15;
    State q16;
    State q17;
    State q18;
    State q19;
    State q20;
    State q21;
    State q22;
    State q23;
    State q24;
    State q25;
    State q26;
    State q27;
    State q28;
    State q29;
    State q30;
    State q31;
    State q32;
    State q33;
    State q34;
    State q35;
    State q36;
    State q37;
    State q38;
    State q39;
    State q40;
    State q41;
    State q42;
    State q43;
    State q44;
    State q45;
    State q46;
    State q47;
    State q48;
    State q49;
    State q50;
    State q51;
    State q52;
    State q53;
    State q54;
    State q55;
    State q56;
    State q57;
    State q58;
    State q59;
    State q60;
    State q61;
    State q62;
    State q63;
    State q64;
    State q65;
    State q66;
    State q67;
    State q68;
    State q69;
    State q70;
    State q71;
    State q72;
    State q73;
    State q74;
    State q75;
    State q76;
    State q77;
    State q78;
    State q79;
    State q80;
    State q81;
    State q82;
    State q83;
    State q84;
    State q85;
    State q86;
    State q87;
    State q88;
    State q89;
    State q90;
    State q91;
    State q92;
    State q93;
    State q94;
    State q95;
    State q96;
    State q97;
    State q98;
    State q99;
    State q100;
    State q101;
    State q102;
    State q103;
    State q104;

    // MAIN LOOP

    q0.addTransition('1', 70, 'I', true);
    q0.addTransition('Y', 0, 'Y', true);

    q70.addTransition('U', 1, 'U', true);
    q70.addTransition('Y', 70, 'Y', true);
    q70.addTransition('X', 70, 'X', true);
    q70.addTransition('W', 70, 'W', true);
    q70.addTransition('0', 70, '0', true);
    q70.addTransition('1', 70, '1', true);
    q70.addTransition('B', 70, 'B', true);

    q49.addTransition('0', 56, 'B', true);
    q49.addTransition('1', 50, 'B', true);
    q49.addTransition('I', 72, 'B', true);
    q49.addTransition('B', 49, 'B', false);

    q50.addTransition('T', 51, 'T', false);
    q50.addTransition('X', 50, 'X', true);
    q50.addTransition('W', 50, 'W', true);
    q50.addTransition('U', 50, 'U', true);
    q50.addTransition('B', 50, 'B', true);
    q50.addTransition('1', 50, '1', true);
    q50.addTransition('0', 50, '0', true);
    q50.addTransition('O', 50, 'O', true);
    q50.addTransition('I', 50, 'I', true);

    q51.addTransition('0', 52, 'O', false);
    q51.addTransition('1', 53, 'I', false);
    q51.addTransition('O', 51, 'O', false);
    q51.addTransition('I', 51, 'I', false);
    q51.addTransition('U', 83, 'U', true);

    q83.addTransition('T', 84, 'T', false);
    q83.addTransition('I', 83, '1', true);
    q83.addTransition('O', 83, '0', true);

    q84.addTransition('W', 56, 'W', true);
    q84.addTransition('U', 84, 'U', false);
    q84.addTransition('0', 84, '0', false);
    q84.addTransition('1', 84, '1', false);
    q84.addTransition('I', 84, '1', false);
    q84.addTransition('O', 84, '0', false);

    q52.addTransition('U', 54, 'U', false);
    q52.addTransition('0', 52, '0', false);
    q52.addTransition('1', 52, '1', false);

    q53.addTransition('U', 55, 'U', false);
    q53.addTransition('0', 53, '0', false);
    q53.addTransition('1', 53, '1', false);

    q54.addTransition('0', 50, 'O', true);
    q54.addTransition('1', 50, 'O', true);
    q54.addTransition('O', 54, 'O', false);
    q54.addTransition('I', 54, 'I', false);

    q55.addTransition('1', 50, 'I', true);
    q55.addTransition('0', 50, 'I', true);
    q55.addTransition('O', 55, 'O', false);
    q55.addTransition('I', 55, 'I', false);

    q56.addTransition('U', 71, 'U', true);
    q56.addTransition('X', 56, 'X', true);
    q56.addTransition('W', 56, 'W', true);
    q56.addTransition('B', 56, 'B', true);
    q56.addTransition('1', 56, '1', true);
    q56.addTransition('0', 56, '0', true);
    q56.addTransition('I', 56, '1', true);
    q56.addTransition('O', 56, '0', true);

    q57.addTransition('T', 60, 'T', true);
    q57.addTransition('0', 57, '0', true);
    q57.addTransition('1', 57, '1', true);

    q58.addTransition('T', 61, 'T', true);
    q58.addTransition('0', 58, '0', true);
    q58.addTransition('1', 58, '1', true);

    q59.addTransition('T', 62, 'T', true);
    q59.addTransition('0', 59, '0', true);
    q59.addTransition('1', 59, '1', true);

    q60.addTransition('B', 63, 'b', true);
    q60.addTransition('1', 63, 'b', true);
    q60.addTransition('0', 63, 'b', true);
    q60.addTransition('b', 60, 'b', true);
    q60.addTransition('I', 60, 'I', true);
    q60.addTransition('O', 60, 'O', true);

    q61.addTransition('B', 64, 'I', true);
    q61.addTransition('1', 64, 'I', true);
    q61.addTransition('0', 64, 'I', true);
    q61.addTransition('b', 61, 'b', true);
    q61.addTransition('I', 61, 'I', true);
    q61.addTransition('O', 61, 'O', true);

    q62.addTransition('B', 65, 'O', true);
    q62.addTransition('1', 65, 'O', true);
    q62.addTransition('0', 65, 'O', true);
    q62.addTransition('b', 62, 'b', true);
    q62.addTransition('I', 62, 'I', true);
    q62.addTransition('O', 62, 'O', true);

    q63.addTransition('Z', 66, 'Z', true);
    q63.addTransition('0', 63, '0', true);
    q63.addTransition('1', 63, '1', true);
    q63.addTransition('B', 63, 'B', true);

    q64.addTransition('Z', 67, 'Z', true);
    q64.addTransition('0', 64, '0', true);
    q64.addTransition('1', 64, '1', true);
    q64.addTransition('B', 64, 'B', true);

    q65.addTransition('Z', 68, 'Z', true);
    q65.addTransition('0', 65, '0', true);
    q65.addTransition('1', 65, '1', true);
    q65.addTransition('B', 65, 'B', true);

    q66.addTransition('B', 69, 'b', false);
    q66.addTransition('1', 69, 'b', false);
    q66.addTransition('0', 69, 'b', false);
    q66.addTransition('b', 66, 'b', true);
    q66.addTransition('I', 66, 'I', true);
    q66.addTransition('O', 66, 'O', true);

    q67.addTransition('B', 69, 'I', false);
    q67.addTransition('1', 69, 'I', false);
    q67.addTransition('0', 69, 'I', false);
    q67.addTransition('b', 67, 'b', true);
    q67.addTransition('I', 67, 'I', true);
    q67.addTransition('O', 67, 'O', true);

    q68.addTransition('B', 69, 'O', false);
    q68.addTransition('1', 69, 'O', false);
    q68.addTransition('0', 69, 'O', false);
    q68.addTransition('b', 68, 'b', true);
    q68.addTransition('I', 68, 'I', true);
    q68.addTransition('O', 68, 'O', true);

    q69.addTransition('U', 71, 'U', true);
    q69.addTransition('0', 69, '0', false);
    q69.addTransition('1', 69, '1', false);
    q69.addTransition('O', 69, 'O', false);
    q69.addTransition('I', 69, 'I', false);
    q69.addTransition('T', 69, 'T', false);
    q69.addTransition('Z', 69, 'Z', false);
    q69.addTransition('B', 69, 'B', false);
    q69.addTransition('b', 69, 'b', false);

    q71.addTransition('I', 73, 'I', true);
    q71.addTransition('O', 71, 'O', true);
    q71.addTransition('T', 74, 'T', false);
    q71.addTransition('0', 57, 'O', true);
    q71.addTransition('1', 58, 'I', true);

    // 72 is unused

    q73.addTransition('T', 74, 'T', false);
    q73.addTransition('I', 73, 'I', true);
    q73.addTransition('O', 73, 'O', true);
    q73.addTransition('0', 59, 'O', true);
    q73.addTransition('1', 58, 'I', true);

    q74.addTransition('U', 79, 'U', false);
    q74.addTransition('I', 74, '0', false);
    q74.addTransition('O', 74, '0', false);

    q79.addTransition('W', 75, 'W', true);
    q79.addTransition('I', 79, '1', false);
    q79.addTransition('O', 79, '0', false);
    q79.addTransition('1', 79, '1', false);
    q79.addTransition('0', 79, '0', false);

    q75.addTransition('S', 2, 'S', false);
    q75.addTransition('T', 75, 'T', true);
    q75.addTransition('U', 75, 'U', true);
    q75.addTransition('Z', 75, 'Z', true);
    q75.addTransition('0', 75, '0', true);
    q75.addTransition('1', 75, '1', true);
    q75.addTransition('B', 75, 'B', true);
    q75.addTransition('b', 75, 'B', true);
    q75.addTransition('I', 75, '1', true);
    q75.addTransition('O', 75, '0', true);

    // MULTIPLICATION
    q1.addTransition('S', 2, 'S', false);
    q1.addTransition('0', 1, '0', true);
    q1.addTransition('1', 1, '1', true);
    q1.addTransition('T', 1, 'T', true);
    q1.addTransition('B', 1, 'B', true);
    q1.addTransition('Z', 1, 'Z', true);

    q2.addTransition('1', 3, 'I', false);
    q2.addTransition('0', 12, 'O', false);
    q2.addTransition('O', 2, 'O', false);
    q2.addTransition('I', 2, 'I', false);
    q2.addTransition('B', 78, 'B', true);

    q3.addTransition('Z', 4, 'Z', false);
    q3.addTransition('1', 3, '1', false);
    q3.addTransition('0', 3, '0', false);
    q3.addTransition('B', 3, 'B', false);

    q4.addTransition('0', 76, 'O', false);
    q4.addTransition('1', 77, 'I', false);
    q4.addTransition('B', 13, 'B', false);
    q4.addTransition('T', 13, 'T', false);
    q4.addTransition('O', 4, 'O', false);
    q4.addTransition('I', 4, 'I', false);

    q76.addTransition('T', 5, 'T', false);
    q76.addTransition('Z', 76, 'Z', false);
    q76.addTransition('B', 76, 'B', false);
    q76.addTransition('O', 76, 'O', false);
    q76.addTransition('I', 76, 'I', false);
    q76.addTransition('0', 76, '0', false);
    q76.addTransition('1', 76, '1', false);

    q77.addTransition('T', 6, 'T', false);
    q77.addTransition('Z', 77, 'Z', false);
    q77.addTransition('B', 77, 'B', false);
    q77.addTransition('O', 77, 'O', false);
    q77.addTransition('I', 77, 'I', false);
    q77.addTransition('0', 77, '0', false);
    q77.addTransition('1', 77, '1', false);

    q5.addTransition('0', 8, 'O', true);
    q5.addTransition('1', 8, 'I', true);
    q5.addTransition('O', 5, 'O', false);
    q5.addTransition('I', 5, 'I', false);
    q5.addTransition('T', 5, 'T', false);
    q5.addTransition('B', 5, 'B', false);

    q6.addTransition('0', 8, 'I', true);
    q6.addTransition('1', 7, 'O', false);
    q6.addTransition('O', 6, 'O', false);
    q6.addTransition('I', 6, 'I', false);
    q6.addTransition('T', 6, 'T', false);
    q6.addTransition('B', 6, 'B', false);

    q7.addTransition('1', 7, '0', false);
    q7.addTransition('0', 8, '1', true);

    q8.addTransition('Z', 4, 'Z', false);
    q8.addTransition('0', 8, '0', true);
    q8.addTransition('1', 8, '1', true);
    q8.addTransition('I', 8, 'I', true);
    q8.addTransition('O', 8, 'O', true);
    q8.addTransition('T', 8, 'T', true);
    q8.addTransition('B', 8, 'B', true);

    q9.addTransition('S', 2, 'S', false);
    q9.addTransition('0', 9, '0', true);
    q9.addTransition('1', 9, '1', true);
    q9.addTransition('Z', 9, 'Z', true);
    q9.addTransition('B', 9, 'B', true);
    q9.addTransition('O', 9, 'O', true);
    q9.addTransition('I', 9, 'I', true);

    q10.addTransition('0', 10, '0', false);
    q10.addTransition('1', 11, '0', false);
    q10.addTransition('B', 9, '0', true);
    q10.addTransition('T', 9, 'T', true);

    q11.addTransition('0', 10, '1', false);
    q11.addTransition('1', 11, '1', false);
    q11.addTransition('B', 9, '1', true);
    q11.addTransition('T', 9, 'T', true);

    q12.addTransition('Z', 10, 'Z', false);
    q12.addTransition('0', 12, '0', false);
    q12.addTransition('1', 12, '1', false);
    q12.addTransition('B', 12, 'B', false);

    q13.addTransition('1', 14, '1', true);
    q13.addTransition('0', 14, '0', true);
    q13.addTransition('U', 14, 'U', true);
    q13.addTransition('B', 13, 'B', false);
    q13.addTransition('T', 13, 'T', false);
    q13.addTransition('O', 13, '0', false);
    q13.addTransition('I', 13, '1', false);

    q14.addTransition('Z', 10, 'Z', false);
    q14.addTransition('T', 14, 'T', true);
    q14.addTransition('B', 14, 'B', true);
    q14.addTransition('1', 14, '1', true);
    q14.addTransition('0', 14, '0', true);
    q14.addTransition('I', 14, '1', true);
    q14.addTransition('O', 14, '0', true);

    q78.addTransition('S', 15, 'S', false);
    q78.addTransition('I', 78, '1', true);
    q78.addTransition('O', 78, '0', true);
    q78.addTransition('B', 78, 'B', true);

    q15.addTransition('X', 86, 'X', true);
    q15.addTransition('Z', 15, 'Z', false);
    q15.addTransition('T', 15, 'T', false);
    q15.addTransition('U', 15, 'U', false);
    q15.addTransition('W', 15, 'W', false);
    q15.addTransition('0', 15, '0', false);
    q15.addTransition('1', 15, '1', false);
    q15.addTransition('O', 15, '0', false);
    q15.addTransition('I', 15, '1', false);
    q15.addTransition('B', 15, 'B', false);

    q86.addTransition('1', 87, '1', false);
    q86.addTransition('0', 86, 'B', true);
    q86.addTransition('B', 86, 'B', true);

    q87.addTransition('X', 17, 'X', true);
    q87.addTransition('B', 87, 'B', false);

    // MODULO
    q17.addTransition('B', 18, 'b', true);
    q17.addTransition('b', 17, 'b', true);
    q17.addTransition('1', 85, '1', true);

    q18.addTransition('U', 19, 'U', true);
    q18.addTransition('B', 18, 'B', true);
    q18.addTransition('W', 18, 'W', true);
    q18.addTransition('1', 18, '1', true);
    q18.addTransition('0', 18, '0', true);

    q19.addTransition('0', 20, 'O', false);
    q19.addTransition('O', 19, 'O', true);
    q19.addTransition('1', 21, '1', false);

    q20.addTransition('X', 17, 'X', true);
    q20.addTransition('U', 20, 'U', false);
    q20.addTransition('W', 20, 'W', false);
    q20.addTransition('0', 20, '0', false);
    q20.addTransition('1', 20, '1', false);
    q20.addTransition('B', 20, 'B', false);
    q20.addTransition('O', 20, 'O', false);
    q20.addTransition('b', 20, 'b', false);

    q21.addTransition('b', 22, 'b', true);
    q21.addTransition('O', 21, '0', false);
    q21.addTransition('I', 21, '1', false);
    q21.addTransition('W', 21, 'W', false);
    q21.addTransition('1', 21, '1', false);
    q21.addTransition('0', 21, '0', false);
    q21.addTransition('B', 21, 'B', false);
    q21.addTransition('U', 21, 'U', false);

    q22.addTransition('0', 23, 'B', false);
    q22.addTransition('1', 24, 'B', false);
    q22.addTransition('B', 22, 'B', true);
    q22.addTransition('W', 27, 'W', false);

    q23.addTransition('1', 25, '1', true);
    q23.addTransition('0', 25, '0', true);
    q23.addTransition('b', 22, '0', true);
    q23.addTransition('B', 23, 'B', false);

    q24.addTransition('1', 26, '1', true);
    q24.addTransition('0', 26, '0', true);
    q24.addTransition('b', 22, '1', true);
    q24.addTransition('B', 24, 'B', false);

    q25.addTransition('B', 22, '0', true);

    q26.addTransition('B', 22, '1', true);

    q85.addTransition('T', 27, 'T', false);
    q85.addTransition('U', 85, 'U', true);
    q85.addTransition('W', 85, 'W', true);
    q85.addTransition('1', 85, '1', true);
    q85.addTransition('0', 85, '0', true);
    q85.addTransition('I', 85, '1', true);
    q85.addTransition('O', 85, '0', true);

    q27.addTransition('X', 28, 'X', true);
    q27.addTransition('1', 27, '1', false);
    q27.addTransition('0', 27, '0', false);
    q27.addTransition('b', 27, '0', false);
    q27.addTransition('B', 27, '0', false);
    q27.addTransition('U', 27, 'U', false);
    q27.addTransition('W', 27, 'W', false);

    q28.addTransition('0', 29, 'O', true);
    q28.addTransition('1', 30, 'I', true);
    q28.addTransition('O', 28, 'O', true);
    q28.addTransition('I', 28, 'I', true);
    q28.addTransition('W', 34, 'W', false);

    q29.addTransition('U', 31, 'U', true);
    q29.addTransition('1', 29, '1', true);
    q29.addTransition('0', 29, '0', true);
    q29.addTransition('W', 29, 'W', true);

    q30.addTransition('U', 32, 'U', true);
    q30.addTransition('1', 30, '1', true);
    q30.addTransition('0', 30, '0', true);
    q30.addTransition('W', 30, 'W', true);

    q31.addTransition('1', 80, 'I', true);
    q31.addTransition('0', 33, 'O', false);
    q31.addTransition('O', 31, 'O', true);
    q31.addTransition('I', 31, 'I', true);

    q32.addTransition('0', 41, '0', false);
    q32.addTransition('1', 33, 'I', false);
    q32.addTransition('O', 32, 'O', true);
    q32.addTransition('I', 32, 'I', true);

    q33.addTransition('b', 28, 'b', true);
    q33.addTransition('X', 28, 'X', true);
    q33.addTransition('O', 33, 'O', false);
    q33.addTransition('I', 33, 'I', false);
    q33.addTransition('U', 33, 'U', false);
    q33.addTransition('W', 33, 'W', false);
    q33.addTransition('1', 33, '1', false);
    q33.addTransition('0', 33, '0', false);

    q80.addTransition('T', 81, 'T', false);
    q80.addTransition('1', 80, 'I', true);
    q80.addTransition('0', 80, 'O', true);

    q81.addTransition('X', 82, 'X', true);
    q81.addTransition('U', 81, 'U', false);
    q81.addTransition('W', 81, 'W', false);
    q81.addTransition('I', 81, 'I', false);
    q81.addTransition('O', 81, 'O', false);
    q81.addTransition('1', 81, '1', false);
    q81.addTransition('0', 81, '0', false);
    q81.addTransition('b', 81, 'b', false);

    q82.addTransition('W', 34, 'W', false);
    q82.addTransition('1', 82, 'I', true);
    q82.addTransition('0', 82, 'O', true);
    q82.addTransition('I', 82, 'I', true);
    q82.addTransition('O', 82, 'O', true);
    q82.addTransition('b', 82, 'b', true);

    q34.addTransition('O', 35, '0', true);
    q34.addTransition('I', 36, '1', true);
    q34.addTransition('0', 34, '0', false);
    q34.addTransition('1', 34, '1', false);
    q34.addTransition('X', 42, 'X', true);

    q35.addTransition('T', 37, 'T', false);
    q35.addTransition('0', 35, '0', true);
    q35.addTransition('1', 35, '1', true);
    q35.addTransition('W', 35, 'W', true);
    q35.addTransition('U', 35, 'U', true);
    q35.addTransition('O', 35, 'O', true);
    q35.addTransition('I', 35, 'I', true);

    q36.addTransition('T', 38, 'T', false);
    q36.addTransition('0', 36, '0', true);
    q36.addTransition('1', 36, '1', true);
    q36.addTransition('W', 36, 'W', true);
    q36.addTransition('U', 36, 'U', true);
    q36.addTransition('O', 36, 'O', true);
    q36.addTransition('I', 36, 'I', true);

    q37.addTransition('O', 40, '0', false);
    q37.addTransition('I', 40, '1', false);
    q37.addTransition('0', 37, '0', false);
    q37.addTransition('1', 37, '1', false);

    q38.addTransition('O', 39, '1', false);
    q38.addTransition('I', 40, '0', false);
    q38.addTransition('0', 38, '0', false);
    q38.addTransition('1', 38, '1', false);

    q39.addTransition('O', 39, 'I', false);
    q39.addTransition('I', 40, 'O', false);

    q40.addTransition('W', 34, 'W', false);
    q40.addTransition('O', 40, 'O', false);
    q40.addTransition('I', 40, 'I', false);
    q40.addTransition('U', 40, 'U', false);
    q40.addTransition('1', 40, '1', false);
    q40.addTransition('0', 40, '0', false);

    q41.addTransition('b', 42, 'b', true);
    q41.addTransition('X', 42, 'X', true);
    q41.addTransition('U', 41, 'U', false);
    q41.addTransition('W', 41, 'W', false);
    q41.addTransition('1', 41, '1', false);
    q41.addTransition('0', 41, '0', false);
    q41.addTransition('O', 41, '0', false);
    q41.addTransition('I', 41, '1', false);

    q42.addTransition('W', 43, 'W', false);
    q42.addTransition('0', 42, '0', true);
    q42.addTransition('1', 42, '1', true);

    q43.addTransition('1', 48, '1', false);
    q43.addTransition('0', 16, '0', false);

    q16.addTransition('b', 44, 'b', true);
    q16.addTransition('X', 44, 'X', true);
    q16.addTransition('1', 16, '1', false);
    q16.addTransition('0', 16, '0', false);

    q44.addTransition('0', 45, '0', true);
    q44.addTransition('1', 46, '0', true);

    q45.addTransition('W', 47, 'W', false);
    q45.addTransition('0', 45, '0', true);
    q45.addTransition('1', 46, '0', true);

    q46.addTransition('W', 47, 'W', false);
    q46.addTransition('0', 45, '1', true);
    q46.addTransition('1', 46, '1', true);

    q47.addTransition('X', 28, 'X', true);
    q47.addTransition('1', 47, '1', false);
    q47.addTransition('0', 47, '0', false);

    q48.addTransition('X', 49, 'X', false);
    q48.addTransition('0', 48, '0', false);
    q48.addTransition('1', 48, '1', false);
    q48.addTransition('b', 48, 'B', false);

    // Final Step
    q72.addTransition('W', 88, 'W', true);
    q72.addTransition('X', 72, 'X', true);
    q72.addTransition('B', 72, 'B', true);
    q72.addTransition('1', 72, '1', true);
    q72.addTransition('0', 72, '0', true);

    q88.addTransition('0', 89, 'O', true);
    q88.addTransition('1', 90, 'I', true);
    q88.addTransition('O', 88, 'O', true);
    q88.addTransition('I', 88, 'I', true);
    q88.addTransition('U', 100, 'U', true);

    q89.addTransition('T', 91, 'T', true);
    q89.addTransition('0', 89, '0', true);
    q89.addTransition('1', 89, '1', true);
    q89.addTransition('O', 89, 'O', true);
    q89.addTransition('I', 89, 'I', true);
    q89.addTransition('U', 89, 'U', true);

    q90.addTransition('T', 92, 'T', true);
    q90.addTransition('0', 90, '0', true);
    q90.addTransition('1', 90, '1', true);
    q90.addTransition('O', 90, 'O', true);
    q90.addTransition('I', 90, 'I', true);
    q90.addTransition('U', 90, 'U', true);

    q91.addTransition('0', 93, 'O', false);
    q91.addTransition('1', 93, 'O', false);
    q91.addTransition('B', 93, 'O', false);
    q91.addTransition('I', 91, 'I', true);
    q91.addTransition('O', 91, 'O', true);

    q92.addTransition('0', 93, 'I', false);
    q92.addTransition('1', 93, 'I', false);
    q92.addTransition('B', 93, 'I', false);
    q92.addTransition('I', 92, 'I', true);
    q92.addTransition('O', 92, 'O', true);

    q93.addTransition('U', 94, 'U', true);
    q93.addTransition('T', 93, 'T', false);
    q93.addTransition('1', 93, '1', false);
    q93.addTransition('0', 93, '0', false);
    q93.addTransition('I', 93, 'I', false);
    q93.addTransition('O', 93, 'O', false);

    q94.addTransition('0', 95, 'O', true);
    q94.addTransition('1', 96, 'I', true);
    q94.addTransition('O', 94, 'O', true);
    q94.addTransition('I', 94, 'I', true);

    q95.addTransition('Z', 97, 'Z', true);
    q95.addTransition('T', 95, 'T', true);
    q95.addTransition('1', 95, '1', true);
    q95.addTransition('0', 95, '0', true);
    q95.addTransition('I', 95, 'I', true);
    q95.addTransition('O', 95, 'O', true);
    q95.addTransition('B', 95, 'B', true);

    q96.addTransition('Z', 98, 'Z', true);
    q96.addTransition('T', 96, 'T', true);
    q96.addTransition('1', 96, '1', true);
    q96.addTransition('0', 96, '0', true);
    q96.addTransition('I', 96, 'I', true);
    q96.addTransition('O', 96, 'O', true);
    q95.addTransition('B', 96, 'B', true);

    q97.addTransition('0', 99, 'O', false);
    q97.addTransition('1', 99, 'O', false);
    q97.addTransition('B', 99, 'O', false);
    q97.addTransition('O', 97, 'O', true);
    q97.addTransition('I', 97, 'I', true);

    q98.addTransition('0', 99, 'I', false);
    q98.addTransition('1', 99, 'I', false);
    q98.addTransition('B', 99, 'I', false);
    q98.addTransition('O', 98, 'O', true);
    q98.addTransition('I', 98, 'I', true);

    q99.addTransition('W', 88, 'W', true);
    q99.addTransition('Z', 99, 'Z', false);
    q99.addTransition('T', 99, 'T', false);
    q99.addTransition('U', 99, 'U', false);
    q99.addTransition('1', 99, '1', false);
    q99.addTransition('0', 99, '0', false);
    q99.addTransition('I', 99, 'I', false);
    q99.addTransition('O', 99, 'O', false);
    q99.addTransition('B', 99, 'B', false);

    q100.addTransition('T', 101, 'T', true);
    q100.addTransition('O', 100, '0', true);
    q100.addTransition('I', 100, '0', true);

    q101.addTransition('I', 102, '1', true);
    q101.addTransition('O', 101, 'B', true);

    q102.addTransition('Z', 103, 'Z', true);
    q102.addTransition('O', 102, '0', true);
    q102.addTransition('I', 102, '1', true);

    q103.addTransition('I', 104, '1', true);
    q103.addTransition('O', 103, 'B', true);

    q104.addTransition('S', 2, 'S', false);
    q104.addTransition('O', 104, '0', true);
    q104.addTransition('I', 104, '1', true);

    // Add All States
    d.addState(q0);
    d.addState(q1);
    d.addState(q2);
    d.addState(q3);
    d.addState(q4);
    d.addState(q5);
    d.addState(q6);
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
    d.addState(q31);
    d.addState(q32);
    d.addState(q33);
    d.addState(q34);
    d.addState(q35);
    d.addState(q36);
    d.addState(q37);
    d.addState(q38);
    d.addState(q39);
    d.addState(q40);
    d.addState(q41);
    d.addState(q42);
    d.addState(q43);
    d.addState(q44);
    d.addState(q45);
    d.addState(q46);
    d.addState(q47);
    d.addState(q48);
    d.addState(q49);
    d.addState(q50);
    d.addState(q51);
    d.addState(q52);
    d.addState(q53);
    d.addState(q54);
    d.addState(q55);
    d.addState(q56);
    d.addState(q57);
    d.addState(q58);
    d.addState(q59);
    d.addState(q60);
    d.addState(q61);
    d.addState(q62);
    d.addState(q63);
    d.addState(q64);
    d.addState(q65);
    d.addState(q66);
    d.addState(q67);
    d.addState(q68);
    d.addState(q69);
    d.addState(q70);
    d.addState(q71);
    d.addState(q72);
    d.addState(q73);
    d.addState(q74);
    d.addState(q75);
    d.addState(q76);
    d.addState(q77);
    d.addState(q78);
    d.addState(q79);
    d.addState(q80);
    d.addState(q81);
    d.addState(q82);
    d.addState(q83);
    d.addState(q84);
    d.addState(q85);
    d.addState(q86);
    d.addState(q87);
    d.addState(q88);
    d.addState(q89);
    d.addState(q90);
    d.addState(q91);
    d.addState(q92);
    d.addState(q93);
    d.addState(q94);
    d.addState(q95);
    d.addState(q96);
    d.addState(q97);
    d.addState(q98);
    d.addState(q99);
    d.addState(q100);
    d.addState(q101);
    d.addState(q102);
    d.addState(q103);
    d.addState(q104);
}