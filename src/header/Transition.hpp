#ifndef __TRANSITION__
#define __TRANSITION__

class Transition {
    private:
        const int nextState;
        const char newSymbol;
        const bool isMoveRight;
    
    public:
        Transition(int, char, bool);
        ~Transition();
        int getNextState() const;
        char getNewSymbol() const;
        bool getIsMoveRight() const;
};

#endif