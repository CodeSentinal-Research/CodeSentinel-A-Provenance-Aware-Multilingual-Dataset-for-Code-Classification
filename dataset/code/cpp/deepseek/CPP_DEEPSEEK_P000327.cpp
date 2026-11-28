#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string ransomNote, magazine;
    cin >> ransomNote >> magazine;

    unordered_map<char, int> freqMap;
    for(char c : magazine) {
        freqMap[c]++;
    }

    for(char c : ransomNote) {
        if(freqMap[c] <= 0) {
            cout << "No";
            return 0;
        }
        freqMap[c]--;
    }
    cout << "Yes";
    return 0;
}