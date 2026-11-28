#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    string text, pattern;
    cin >> text >> pattern;

    unordered_map<string, int> freq;

    for (int i = 0; i < text.size() - pattern.size() + 1; i++) {
        string substring = text.substr(i, pattern.size());
        freq[substring]++;
    }

    cout << freq[pattern];

    return 0;
}