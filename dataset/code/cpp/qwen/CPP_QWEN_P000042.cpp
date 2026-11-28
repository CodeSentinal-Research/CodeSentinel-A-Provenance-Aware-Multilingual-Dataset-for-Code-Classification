#include <iostream>
using namespace std;

int main() {
    char c;
    cin >> c;
    c = tolower(c);
    bool isVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    cout << (isVowel ? "Vowel" : "Consonant") << endl;
    return 0;
}
