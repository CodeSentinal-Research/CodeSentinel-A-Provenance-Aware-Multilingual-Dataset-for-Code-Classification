#include <iostream>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> m;
    for(int i = 0; i < s.length(); i++) {
        m[s[i]]++;
    }

    for(int i = 0; i < s.length(); i++) {
        if(m[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    string s;
    cin >> s;
    cout << firstUniqChar(s);
    return 0;
}
This C++ program first counts the frequency of each character in the string using an unordered map. Then it iterates over the string and returns the index of the first character that has a frequency of 1. If no such character exists, it returns -1.