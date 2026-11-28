#include <stdio.h>
#include <ctype.h>

/* Clear Digits from String */
int main(void) {
    char s[200000], out[200000];
    int top = 0;
    if (scanf("%199999s", s) != 1) return 1;
    for (int i = 0; s[i]; i++) {
        if ((s[i] == '*' || isdigit((unsigned char)s[i])) && top > 0) top--;
        else if (s[i] != '*') out[top++] = s[i];
    }
    out[top] = '\0';
    printf("%s\n", out);

    return 0;
}
