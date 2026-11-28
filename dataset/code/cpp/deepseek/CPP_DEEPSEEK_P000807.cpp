Here is the C++ code to solve the problem:

#include <iostream>
#include <cstring>
using namespace std;

int countSubarrays(string s) {
    int n = s.length();
    int vowelCount = 0, consonantCount = 0;
    int vowels[26] = {0}, consonants[26] = {0};

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            vowelCount++;
            vowels[s[i] - 'a']++;
        } else {
            consonantCount++;
            consonants[s[i] - 'a']++;
        }

        vowelCount += vowels[s[i] - 'a'];
        consonantCount += consonants[s[i] - 'a'];

        cout << vowelCount << " " << consonantCount << endl;
    }

    return 0;
}

int main() {
    string s;
    cin >> s;
    countSubarrays(s);
    return 0;
}

This code will handle the input string as a stream. It counts the number of vowels and consonants in the string, and then prints out the number of subarrays with the same number of vowels and consonants.