#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    
    if (n < 10) {
        cout << "" << endl;
        return 0;
    }
    
    unordered_map<string, int> freq;
    vector<string> result;
    
    for (int i = 0; i <= n - 10; ++i) {
        string sub = s.substr(i, 10);
        freq[sub]++;
        if (freq[sub] == 2) {
            result.push_back(sub);
        }
    }
    
    for (const string& seq : result) {
        cout << seq << endl;
    }
    
    return 0;
}
