#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    string s1 = s.substr(0, s.length()/2);
    string s2 = s.substr(s.length()/2, s.length()/2);
    int vowel_count1 = 0, vowel_count2 = 0;
    for(int i = 0; i < s1.length(); i++) {
        if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u' || s1[i] == 'A' || s1[i] == 'E' || s1[i] == 'I' || s1[i] == 'O' || s1[i] == 'U') {
            vowel_count1++;
        }
    }
    for(int i = 0; i < s2.length(); i++) {
        if(s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o' || s2[i] == 'u' || s2[i] == 'A' || s2[i] == 'E' || s2[i] == 'I' || s2[i] == 'O' || s2[i] == 'U') {
            vowel_count2++;
        }
    }
    if(vowel_count1 == vowel_count2) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
This program takes a string as input, extracts the two halves of the string, counts the number of vowels in each half, and then compares these counts. If they match, it prints "Yes", otherwise it prints "No".