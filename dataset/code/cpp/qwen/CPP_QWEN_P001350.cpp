#include <iostream>
#include <string>
#include <vector>
using namespace std;

void generateHappyStrings(int n, int k, string current, vector<string>& result) {
    if (current.length() == n) {
        result.push_back(current);
        return;
    }
    
    for (char c = 'a'; c <= 'c'; ++c) {
        if (current.empty() || current.back() != c) {
            generateHappyStrings(n, k, current + c, result);
            if (result.size() == k) return;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> result;
    generateHappyStrings(n, k, "", result);
    
    if (k <= result.size()) {
        cout << result[k-1] << endl;
    } else {
        cout << "" << endl;
    }
    return 0;
}
