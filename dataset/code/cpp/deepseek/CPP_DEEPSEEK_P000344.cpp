#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countPrefixes(vector<string>& words, string S) {
    int count = 0;
    for (string word : words) {
        if (word.find(S) == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<string> words = {"flower", "flow", "flight"};
    string S = "fl";
    cout << countPrefixes(words, S);
    return 0;
}