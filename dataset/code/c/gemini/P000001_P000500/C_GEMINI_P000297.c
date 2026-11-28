#include <stdio.h>
#include <string.h>
int val(char c) {
    switch(c) {
        case 'I': return 1; case 'V': return 5; case 'X': return 10;
        case 'L': return 50; case 'C': return 100; case 'D': return 500; case 'M': return 1000;
        default: return 0;
    }
}
int main() {
    char s[100];
    if (scanf("%99s", s) == 1) {
        int total = 0, len = strlen(s);
        for (int i = 0; i < len; i++) {
            int v = val(s[i]);
            if (i + 1 < len && v < val(s[i + 1])) total -= v;
            else total += v;
        }
        printf("%d\n", total);
    }
    return 0;
}