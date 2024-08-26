#include "../header/State.hpp"

#include <sstream>

int State::stateCount = 0;

State::State() : stateName("q" + to_string(stateCount)) {
    stateCount++;
}

State::~State() {}

string State::getStateName() const {
    return this->stateName;
}

unordered_map<char, Transition> State::getTransitions() const {
    return this->transitions;
}

void State::addTransition(char c, int next, char s, bool r) {
    this->transitions.insert({c, Transition(next, s, r)});
}