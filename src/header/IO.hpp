#ifndef __IO__
#define __IO__

#include <iostream>
#include <vector>

using namespace std;

class IO {
    public:
        IO();
        void showTitle();
        void askInputs();
        bool checkBooleanInput(string);
        void doAlgorithm(bool, bool, string, bool);
        bool askToRepeat();
};

#endif