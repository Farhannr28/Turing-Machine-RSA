#include "../header/Transition.hpp"

using namespace std;

Transition::Transition(int state, char symbol, bool right) : nextState(state), newSymbol(symbol), isMoveRight(right) {}

Transition::Transition() : nextState(-1), newSymbol(' '), isMoveRight(false) {}

Transition::~Transition(){}

int Transition::getNextState() const {
    return this->nextState;
}

char Transition::getNewSymbol() const {
    return this->newSymbol;
}

bool Transition::getIsMoveRight() const {
    return this->isMoveRight;
}