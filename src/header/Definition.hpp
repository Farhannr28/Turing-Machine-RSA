#ifndef __DEFINITON__
#define __DEFINITON__

#include <vector>

#include "State.hpp"

class Definition {
    private:
        vector<State> states;
        // input symbols : Alphanumeric
        // tape symbols : Up To 255 ASCII characters
        int startState;
        vector<int> acceptingStates;
    public:
        Definition();
        ~Definition();
        const static char BLANK_SYMBOL;
        vector<State> getStates() const;
        int getStartState() const;
        vector<int> getAcceptingStates() const;
        void addState(State s);
        void addAcceptingState(int s);
        void setStartState(int);
        bool isAcceptByHalt();
};

#endif