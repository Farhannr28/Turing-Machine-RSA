#ifndef __UTIL__
#define __UTIL__

#include <vector>
#include <iostream>

using namespace std;

class Util {

    public:
        static vector<string> splitIntoGroupsOfThree(const string& input);
        static vector<string> splitIntoGroupsOfTwo(const string& input);
};

#endif