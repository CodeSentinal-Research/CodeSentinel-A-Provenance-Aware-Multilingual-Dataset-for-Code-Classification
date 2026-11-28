Here is the C++ code:

#include <iostream>
using namespace std;

int countConsonants(string s) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') 
        {
            continue;
        }
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
        {
            count++;
        }
    }
    return count;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Number of consonants: " << countConsonants(s) << endl;
    return 0;
}

This program firstly takes a string as input from the user. It then calls the `countConsonants` function to count the consonants in the string and prints the result. The `countConsonants` function iterates over each character in the string. If the character is a vowel (both lower and upper case), it ignores it. Otherwise, it increments a counter. Finally, it returns the count of consonants.