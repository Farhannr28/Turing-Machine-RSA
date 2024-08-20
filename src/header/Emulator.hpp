#ifndef __EMULATOR__
#define __EMULATOR__

#include "Definition.hpp"

class Emulator {
    private:
        Definition definition;
        int currentState;
        int finiteControlIndex;
        vector<char> tape;
    public:
        static const int initialTapeSize;
        Emulator(int);
        ~Emulator();
        Definition getDefinition() const;
        int getCurrentState() const;
        int getFiniteControlIndex() const;
        vector<char> getTape() const;
        char readSymbol();
        void changeCurrentState(int);
        void moveFiniteControl(bool);
        void writeSymbol(char);
        void setInitialTape(vector<char>&);
        void elongateTape(); // Fill tape until capacity with BLANK_SYMBOL when finite control reaches end
};

#endif