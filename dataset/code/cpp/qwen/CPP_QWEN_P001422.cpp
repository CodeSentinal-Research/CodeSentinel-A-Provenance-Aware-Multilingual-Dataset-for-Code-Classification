#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    vector<unordered_set<char>> rows = {
        {'q','w','e','r','t','y','u','i','o','p'},
        {'a','s','d','f','g','h','j','k','l'},
        {'z','x','c','v','b','n','m'}
    };
    
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) cin >> words[i];
    
    for (const string& w : words) {
        if (w.empty()) continue;
        char first = tolower(w[0]);
        int rowIdx = -1;
        for (int i = 0; i < 3; ++i) {
            if (rows[i].count(first)) {
                rowIdx = i;
                break;
            }
        }
        
        bool valid = true;
        for (char c : w) {
            if (!rows[rowIdx].count(tolower(c))) {
                valid = false;
                break;
            }
        }
        
        if (valid) cout << w << endl;
    }
    
    return 0;
}
