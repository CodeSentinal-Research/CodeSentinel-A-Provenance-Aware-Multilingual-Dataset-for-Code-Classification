#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> m;
    for(char c : s) {
        m[c]++;
    }
    int deletions = 0;
    for(auto it : m) {
        if(it.second > 1) {
            while(it.second > 1) {
                it.second -= 1;
                deletions++;
            }
        }
    }
    cout << deletions;
    return 0;
}
This program takes a string as input and then counts the frequency of each character in the string. It then iterates through these frequencies and decrements them until they are 0 or 1. The number of deletions required is incremented each time. This process repeats until all characters have a frequency of 1. The total number of deletions is then printed.