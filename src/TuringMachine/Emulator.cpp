#include "../header/printColor.hpp"
#include "../header/Emulator.hpp"
#include "../header/Definition.hpp"

Emulator::Emulator() : definition(), tape() {}

Emulator::~Emulator(){}

Definition& Emulator::getDefinition() {
    return this->definition;
}

int Emulator::getCurrentState() const {
    return this->currentState;
}

int Emulator::getFiniteControlIndex() const {
    return this->finiteControlIndex;
}

vector<char>& Emulator::getTape() {
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
        // if (finiteControlIndex == (int) this->tape.size() - 1){
        //     elongateTape();
        // }
    } else {
        this->finiteControlIndex--;
    }
}

void Emulator::writeSymbol(char s){
    this->tape[this->finiteControlIndex] = s;
}

void Emulator::setInitialTape(vector<char>& v){
    this->tape.clear();
    int sz = v.size();
    for (int i=0; i<sz; i++) {
        this->tape.push_back(v[i]);
    }
}

void Emulator::elongateTape(){
    int cap = this->tape.capacity();
    int sz = this->tape.size();
    for (int i=0; i<cap-sz; i++){
        this->tape.push_back(Definition::BLANK_SYMBOL);
    }
}

/* BINARY VERSION */
void Emulator::printTape(int num, int total){
    int idx = this->finiteControlIndex;
    resetTextColor();
    for (int i=0; i<idx; i++){
        cout << this->tape[i];
    }
    startTextBlue();
    cout << this->tape[idx];
    resetTextColor();
    for (int i=idx+1; i<82; i++){
        cout << this->tape[i];
    }
    startTextRed();
    cout << " State: ";
    cout << this->currentState;
    startTextGreen();
    cout << " [";
    cout << num;
    cout << "/";
    cout << total;
    cout << "]\n";
}

bool Emulator::run(bool print, int num, int total){

    //ios_base::sync_with_stdio(false);

    char rs;
    int nextState;
    char newSymbol;
    bool moveRight;

    this->currentState = this->definition.getStartState();
    this->finiteControlIndex = 0;
    rs = this->readSymbol();

    while (this->getDefinition().getStates()[this->currentState].getTransitions().count(rs) > 0){
        nextState = this->getDefinition().getStates()[this->currentState].getTransitions().at(rs).getNextState();
        newSymbol = this->getDefinition().getStates()[this->currentState].getTransitions().at(rs).getNewSymbol();
        moveRight = this->getDefinition().getStates()[this->currentState].getTransitions().at(rs).getIsMoveRight();

        if (print){
            printTape(num, total);
        }

        this->writeSymbol(newSymbol);
        this->moveFiniteControl(moveRight);
        this->changeCurrentState(nextState);
        rs = this->readSymbol();

    }

    if (this->getDefinition().isAcceptByHalt()){
        return this->currentState == 49 && this->readSymbol() == 'Y'; // Halt
    } else {
        for (int as : this->getDefinition().getAcceptingStates()){
            if (as == this->currentState){
                return true; // Accepted
            }
        }
    }
    return false; // Rejected
}