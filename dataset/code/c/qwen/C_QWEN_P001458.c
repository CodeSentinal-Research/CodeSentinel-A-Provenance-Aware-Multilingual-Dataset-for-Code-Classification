#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);
    int n = strlen(s);
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int pal = 1;
            for (int l = i, r = j; l < r; l++, r--) {
                if (s[l] != s[r]) { pal = 0; break; }
            }
            if (pal) count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
