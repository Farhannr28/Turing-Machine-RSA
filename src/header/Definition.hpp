#ifndef __DEFINITON__
#define __DEFINITON__

#include <vector>

#include "State.hpp"

class Definition {
    private:
        vector<State> states;
        // input symbols : Alphanumeric
        // tape symbols : Up To 255 ASCII characters
        const int startState;
        vector<State> acceptingStates;
    public:
        Definition(int x);
        ~Definition();
        const static char BLANK_SYMBOL;
        vector<State> getStates() const;
        int getStartState() const;
        vector<State> getAcceptingStates() const;
        void addState(State s);
        void addAcceptingState(State s);
        bool isAcceptByHalt();
};

#endif