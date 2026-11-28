Here is the C++ code that fulfills your requirements:

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

bool areSentencesSimilar(string a, string b, int p, pair<string, string>* pairs) {
    if (a == b) {
        return true;
    }
    for (int i = 0; i < p; i++) {
        pair<string, string> pair = pairs[i];
        if ((a.find(pair.first) != string::npos && b.find(pair.second) != string::npos) ||
            (a.find(pair.second) != string::npos && b.find(pair