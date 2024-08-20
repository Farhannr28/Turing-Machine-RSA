#ifndef __STATE__
#define __STATE__

#include <string>
#include <unordered_map>

#include "Transition.hpp"

using namespace std;

class State {
    private:
        static int stateCount; // Actual state count - 1
        const string stateName;
        unordered_map<char, Transition> transitions;
    public:
        State();
        ~State();
        string getStateName() const;
        unordered_map<char, Transition> getTransitions() const;
        void addTransition(char, int, char, bool);
};

#endif