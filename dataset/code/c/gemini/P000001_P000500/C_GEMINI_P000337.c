#include <stdio.h>
#include <string.h>

int main() {
    char s[505];
    if (scanf("%504s", s) == 1) {
        int n = strlen(s);
        int ones = 0;
        for (int i = 0; i < n; i++) if (s[i] == '1') ones++;
        int max_score = 0, zeros = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') zeros++;
            else ones--;
            if (zeros + ones > max_score) max_score = zeros + ones;
        }
        printf("%d\n", max_score);
    }
    return 0;
}