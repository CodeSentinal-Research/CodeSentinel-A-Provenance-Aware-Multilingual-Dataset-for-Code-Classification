#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    string allowed;
    cin >> allowed;
    unordered_set<char> allowedSet(allowed.begin(), allowed.end());
    
    int n;
    cin >> n;
    int count = 0;
    while (n--) {
        string word;
        cin >> word;
        bool consistent = true;
        for (char c : word) {
            if (allowedSet.find(c) == allowedSet.end()) {
                consistent = false;
                break;
            }
        }
        if (consistent) count++;
    }
    
    cout << count << endl;
    return 0;
}
