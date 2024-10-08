#include<iostream>

#include "../header/Definition.hpp"

const char Definition::BLANK_SYMBOL = 'B';

Definition::Definition() {}

Definition::~Definition(){}

vector<State> Definition::getStates() const {
    return this->states;
}

int Definition::getStartState() const {
    return this->startState;
}

vector<int> Definition::getAcceptingStates() const {
    return this->acceptingStates;
}

void Definition::setStartState(int s) {
    this->startState = s;
}

void Definition::addState(State s){
    this->states.push_back(s);
}

void Definition::addAcceptingState(int s){
    this->acceptingStates.push_back(s);
}

bool Definition::isAcceptByHalt(){
    return this->acceptingStates.empty();
}