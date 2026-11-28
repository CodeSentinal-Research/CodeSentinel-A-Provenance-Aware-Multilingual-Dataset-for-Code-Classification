#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];
    string row1 = "qwertyuiop", row2 = "asdfghjkl", row3 = "zxcvbnm";
    for (const string& word : words) {
        char first = tolower(word[0]);
        string row;
        if (row1.find(first) != string::npos) row = row1;
        else if (row2.find(first) != string::npos) row = row2;
        else row = row3;
        bool ok = true;
        for (char c : word) {
            if (row.find(tolower(c)) == string::npos) { ok = false; break; }
        }
        if (ok) cout << word << endl;
    }
    return 0;
}
