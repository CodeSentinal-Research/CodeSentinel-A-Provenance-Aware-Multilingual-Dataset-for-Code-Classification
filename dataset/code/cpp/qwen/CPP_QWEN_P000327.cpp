#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string ransom, magazine;
    cin >> ransom >> magazine;
    unordered_map<char, int> count;
    for (char c : magazine) count[c]++;
    for (char c : ransom) {
        if (count[c] <= 0) { cout << "No" << endl; return 0; }
        count[c]--;
    }
    cout << "Yes" << endl;
    return 0;
}
