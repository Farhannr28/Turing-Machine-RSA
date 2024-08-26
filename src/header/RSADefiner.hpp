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
        RSADefiner();
        ~RSADefiner();
        void setP(int x);
        void setQ(int x);
        void setD(int x);
        void setE(int x);
        void define(Definition&);
        vector<char> createInitialTape(int);
        int readTapeResult(vector<char>&);
};

#endif