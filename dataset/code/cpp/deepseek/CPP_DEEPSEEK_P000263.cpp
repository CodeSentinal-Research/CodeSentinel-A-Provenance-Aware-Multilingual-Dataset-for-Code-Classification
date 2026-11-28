Here is the C++ code:

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    unordered_map<char, int> count;
    for(char c : s) {
        count[c]++;
    }

    for(int i = s.length() - 1; i >= 0; i--) {
        if(count[s[i]] == 1) {
            cout << s[i] << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
This program first reads the string. Then it counts the frequency of each character in the string. Afterwards, it iterates over the string in reverse order and checks the frequency of each character. If the frequency of a character is 1, that means it is the last non-repeating character, so it prints the character and stops the execution. If no non-repeating character is found after the iteration, it prints -1.