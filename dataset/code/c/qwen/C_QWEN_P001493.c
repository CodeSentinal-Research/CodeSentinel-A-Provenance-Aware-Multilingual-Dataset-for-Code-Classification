#include <stdio.h>
#include <string.h>

int main() {
    char s[200001];
    char c;
    scanf("%s %c", s, &c);
    int n = strlen(s);
    
    int last = -1000000;
    int res[n];
    for (int i = 0; i < n; i++) {
        if (s[i] == c) last = i;
        res[i] = i - last;
    }
    last = 1000000;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == c) last = i;
        if (last - i < res[i]) res[i] = last - i;
    }
    for (int i = 0; i < n; i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
