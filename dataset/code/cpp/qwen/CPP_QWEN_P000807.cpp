#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int diff = 0; // count(vowels) - count(consonants)
    long long count = 0;
    
    string vowels = "aeiou";

    for (char c : s) {
        if (vowels.find(c) != string::npos) diff++;
        else diff--;
        
        if (prefixCount.find(diff) != prefixCount.end()) {
            count += prefixCount[diff];
        }
        prefixCount[diff]++;
    }

    cout << count << endl;
    return 0;
}
