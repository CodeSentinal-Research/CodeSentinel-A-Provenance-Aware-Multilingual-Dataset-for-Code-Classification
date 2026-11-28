#include <iostream>
#include <string>
#include <vector>
using namespace std;

void generateCombinations(string s, int k, int start, string current, vector<string>& result) {
    if (current.length() == k) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < s.length(); ++i) {
        generateCombinations(s, k, i + 1, current + s[i], result);
    }
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    vector<string> result;
    generateCombinations(s, k, 0, "", result);
    
    for (const string& comb : result) {
        cout << comb << endl;
    }
    return 0;
}
