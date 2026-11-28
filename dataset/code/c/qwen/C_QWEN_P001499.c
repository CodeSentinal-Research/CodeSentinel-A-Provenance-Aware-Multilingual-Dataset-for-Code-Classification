#include <stdio.h>
#include <string.h>

int main() {
    char s[200001];
    char c;
    scanf("%s %c", s, &c);
    
    int idx = -1;
    for (int i = 0; s[i]; i++) {
        if (s[i] == c) { idx = i; break; }
    }
    if (idx != -1) {
        int l = 0, r = idx;
        while (l < r) { char t = s[l]; s[l] = s[r]; s[r] = t; l++; r--; }
    }
    printf("%s\n", s);
    return 0;
}
