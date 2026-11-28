#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        unordered_set<char> substring;
        for (int j = i; j < s.length() && substring.size() < 5; j++) {
            if (vowels.find(s[j]) != vowels.end()) {
                substring.insert(s[j]);
            }
        }
        if (substring.size() == 5) {
            count++;
        }
    }
    
    cout << count << endl;
    return 0;
}
This code reads a string from the standard input, and then iterates over each character in the string. For each character, it checks if it is a vowel. If it is, it adds it to a set (which automatically removes duplicates). This process continues until a set of five characters is found, at which point it increments the count. The final count is then printed out.