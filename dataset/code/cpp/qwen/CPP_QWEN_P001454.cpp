#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    
    unordered_set<string> substrings;
    for (int i = 0; i < n; ++i) {
        string curr = "";
        for (int j = i; j < n; ++j) {
            curr += s[j];
            substrings.insert(curr);
        }
    }
    
    cout << substrings.size() << endl;
    return 0;
}
