#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

long long countEqualVowelsConsonants(const char* s) {
    int len = strlen(s);
    long long count = 0;
    for (int i = 0; i < len; i++) {
        int v = 0, c = 0;
        for (int j = i; j < len; j++) {
            if (isalpha(s[j])) {
                if (isVowel(s[j])) v++;
                else c++;
                if (v == c) count++;
            }
        }
    }
    return count;
}

int main() {
    char s[2000];
    if (scanf("%1999s", s) == 1) {
        printf("%lld\n", countEqualVowelsConsonants(s));
    }
    return 0;
}