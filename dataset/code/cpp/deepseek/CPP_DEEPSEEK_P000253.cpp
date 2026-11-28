#include <iostream>
#include <string>
using namespace std;

int countVowels(string s) {
    int count = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U') {
            count++;
        }
    }
    return count;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    cout << "Number of vowels: " << countVowels(s) << endl;
    return 0;
}