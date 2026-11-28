#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    
    string target = "balloon";
    unordered_map<char, int> targetFreq;
    for (char c : target) targetFreq[c]++;
    
    int minInstances = INT_MAX;
    for (auto& p : targetFreq) {
        minInstances = min(minInstances, freq[p.first] / p.second);
    }
    
    cout << minInstances << endl;
    return 0;
}
