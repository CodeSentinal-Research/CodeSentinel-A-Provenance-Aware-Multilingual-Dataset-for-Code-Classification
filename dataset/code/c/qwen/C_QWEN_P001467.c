#include <stdio.h>
#include <string.h>

int is_vowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    char s[200001];
    scanf("%s", s);
    
    int l = 0, r = strlen(s) - 1;
    while (l < r) {
        while (l < r && !is_vowel(s[l])) l++;
        while (l < r && !is_vowel(s[r])) r--;
        if (l < r) { char t = s[l]; s[l] = s[r]; s[r] = t; l++; r--; }
    }
    printf("%s\n", s);
    return 0;
}
