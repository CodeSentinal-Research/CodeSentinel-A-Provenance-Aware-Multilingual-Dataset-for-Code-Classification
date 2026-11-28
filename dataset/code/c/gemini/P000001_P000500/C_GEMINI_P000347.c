#include <stdio.h>
#include <string.h>

int main() {
    char s[1005];
    int k;
    if (scanf("%1004s %d", s, &k) == 2) {
        int n = strlen(s);
        for (int start = 0; start < n; start += 2 * k) {
            int i = start, j = start + k - 1;
            if (j >= n) j = n - 1;
            while (i < j) {
                char tmp = s[i];
                s[i++] = s[j];
                s[j--] = tmp;
            }
        }
        printf("%s\n", s);
    }
    return 0;
}