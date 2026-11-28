#include <stdio.h>

int main(void) {
    char ch;
    if (scanf(" %c", &ch) != 1) return 1;
    char lower = (ch >= 'A' && ch <= 'Z') ? (char)(ch + 32) : ch; if (lower=='a'||lower=='e'||lower=='i'||lower=='o'||lower=='u') printf("Vowel\n"); else if (lower >= 'a' && lower <= 'z') printf("Consonant\n"); else printf("Not Alphabet\n");
    return 0;
}
