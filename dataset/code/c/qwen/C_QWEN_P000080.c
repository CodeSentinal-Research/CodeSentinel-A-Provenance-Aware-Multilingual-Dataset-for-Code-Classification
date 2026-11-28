#include <stdio.h>

int main() {
    char c;
    scanf(" %c", &c);
    printf("%s\n", ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? "Alphabet" : "Not Alphabet");
    return 0;
}
