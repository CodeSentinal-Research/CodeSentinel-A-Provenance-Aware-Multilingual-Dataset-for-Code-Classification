// Q115: Write a program to take two strings s and t as inputs (assume all characters are lowercase). The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. Print "Anagram" if they are, otherwise "Not Anagram".

// /*
// Sample Test Cases:
// Input 1:
// s = "anagram", t = "nagaram"
// Output 1:
// Anagram

// Input 2:
// s = "rat", t = "car"
// Output 2:
// Not Anagram

// */


#include <stdio.h>

int main() {
    char s[1000], t[1000];
    int freq1[26] = {0}, freq2[26] = {0};
    int i = 0, j = 0, flag = 1;

    fgets(s, sizeof(s), stdin);
    fgets(t, sizeof(t), stdin);

    while (s[i] != '\0' && s[i] != '\n') {
        freq1[s[i] - 'a']++;
        i++;
    }

    while (t[j] != '\0' && t[j] != '\n') {
        freq2[t[j] - 'a']++;
        j++;
    }

    for (int k = 0; k < 26; k++)
        if (freq1[k] != freq2[k])
            flag = 0;

    if (flag) printf("Anagram");
    else printf("Not Anagram");

    return 0;
}
