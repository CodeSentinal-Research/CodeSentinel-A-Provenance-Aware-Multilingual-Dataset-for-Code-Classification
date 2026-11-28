#include <stdio.h>
#include <ctype.h>
int main() {
    char ch;
    if (scanf(" %c", &ch) == 1) {
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') printf("Vowel\n");
        else printf("Consonant\n");
    }
    return 0;
}