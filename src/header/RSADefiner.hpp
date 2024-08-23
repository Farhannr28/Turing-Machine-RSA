#ifndef __RSADEFINER__
#define __RSADEFINER__

#include <vector>

#include "Definition.hpp"
#include "Emulator.hpp"

using namespace std;

class RSADefiner {
    private:
        int P;
        int Q;
        int D;
        int E;
    public:
        RSADefiner(int, int, int, int);
        ~RSADefiner();
        void define(Definition&);
        vector<char>& createInitialTape(vector<int>&, bool);
        vector<int> readTapeResult(vector<char>&);
};

#endif