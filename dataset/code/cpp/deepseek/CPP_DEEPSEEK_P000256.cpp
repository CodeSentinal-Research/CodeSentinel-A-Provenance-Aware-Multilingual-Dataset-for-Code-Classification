#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str[1000];
    cout << "Enter a string: ";
    cin.getline(str, 1000);

    char vowels[] = "aeiouAEIOU";

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (strchr(vowels, str[i]) == NULL) {
            str[i] = str[i + 1];
        }
    }

    cout << "After removing consonants: " << str;

    return 0;
}
This C++ program will take an input string, check each character in the string, and if the character is not a vowel (i.e., a consonant), then it replaces it with the next character. Therefore, all the consonants from the given string will be removed.