#include "../header/Emulator.hpp"
#include "../header/Definition.hpp"

const int Emulator::initialTapeSize = 6500;

Emulator::Emulator(int _startState) : definition(_startState), tape(Emulator::initialTapeSize, Definition::BLANK_SYMBOL) {}

Emulator::~Emulator(){}

Definition Emulator::getDefinition() const {
    return this->definition;
}

int Emulator::getCurrentState() const {
    return this->currentState;
}

int Emulator::getFiniteControlIndex() const {
    return this->finiteControlIndex;
}

vector<char> Emulator::getTape() const {
    return this->tape;
}

char Emulator::readSymbol(){
    return this->tape[this->finiteControlIndex];
}

void Emulator::changeCurrentState(int q){
    this->currentState = q;
}

void Emulator::moveFiniteControl(bool right){
    if (right){
        this->finiteControlIndex++;
        if (finiteControlIndex == (int) this->tape.size()){
            elongateTape();
        }
    } else {
        this->finiteControlIndex--;
    }
}

void Emulator::writeSymbol(char s){
    this->tape[this->finiteControlIndex] = s;
}

void Emulator::setInitialTape(vector<char>& v){
    int sz = v.size();
    for (int i=0; i<sz; i++){
        this->tape[i] = v[i];
    }
}

void Emulator::elongateTape(){
    int cap = this->tape.capacity();
    int sz = this->tape.size();
    for (int i=0; i<cap-sz; i++){
        this->tape.push_back(Definition::BLANK_SYMBOL);
    }
}

bool Emulator::run(){
    char rs;
    int nextState;
    char newSymbol;
    bool moveRight;

    this->currentState = this->definition.getStartState();
    this->finiteControlIndex = 0;

    while (this->getDefinition().getStates()[this->currentState].getTransitions().count(rs) > 0){
        rs = this->readSymbol();
        nextState = this->getDefinition().getStates()[this->currentState].getTransitions().at(rs).getNextState();
        newSymbol = this->getDefinition().getStates()[this->currentState].getTransitions().at(rs).getNewSymbol();
        moveRight = this->getDefinition().getStates()[this->currentState].getTransitions().at(rs).getIsMoveRight();
        this->writeSymbol(newSymbol);
        this->moveFiniteControl(moveRight);
        this->changeCurrentState(nextState);
    }

    if (this->getDefinition().isAcceptByHalt()){
        return true; // Halt
    } else {
        for (int as : this->getDefinition().getAcceptingStates()){
            if (as == this->currentState){
                return true; // Accepted
            }
        }
    }
    return false; // Rejected
}