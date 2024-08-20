#include "../header/State.hpp"

int State::stateCount = 0;

State::State() : stateName("q" + stateCount) {
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