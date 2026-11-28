#include <stdio.h>
#include <string.h>

int is_pal(char *s, int l, int r) {
    while (l < r) { if (s[l++] != s[r--]) return 0; }
    return 1;
}

int main() {
    char s[200001];
    scanf("%s", s);
    int n = strlen(s);
    
    int l = 0, r = n - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            printf("%s\n", is_pal(s, l+1, r) || is_pal(s, l, r-1) ? "YES" : "NO");
            return 0;
        }
        l++; r--;
    }
    printf("YES\n");
    return 0;
}
