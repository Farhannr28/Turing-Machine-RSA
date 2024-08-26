#include <iostream>

#include "header/IO.hpp"

using namespace std;

int main(){
    IO io;
    bool repeat = true;
    while (repeat){
        io.askInputs();
        repeat = io.askToRepeat();
    }
    return 0;
}