#include <stdio.h>
#include <string.h>

int main() {
    char s[200001];
    scanf("%s", s);
    int n = strlen(s);
    
    int black = 0;
    for (int i = 0; i < n; i++) if (s[i] == '1') black++;
    
    long long swaps = 0;
    int pos = black - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') { swaps += pos - i; pos--; }
    }
    printf("%lld\n", swaps);
    return 0;
}
