#include "../header/Util.hpp"

using namespace std;

vector<string> Util::splitIntoGroupsOfThree(const string& input) {
    vector<string> groups;
    for (size_t i = 0; i < input.length(); i += 3) {
        groups.push_back(input.substr(i, 3));
    }
    return groups;
}