#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char s[10005], p[10005];
    if (scanf("%s %s", s, p) == 2) {
        int sLen = strlen(s), pLen = strlen(p);
        if (sLen < pLen) {
            printf("0\n");
            return 0;
        }

        int pCount[26] = {0}, sCount[26] = {0};
        for (int i = 0; i < pLen; i++) pCount[p[i] - 'a']++;

        int ans = 0;
        for (int i = 0; i < sLen; i++) {
            sCount[s[i] - 'a']++;
            if (i >= pLen) sCount[s[i - pLen] - 'a']--;
            bool match = true;
            for (int j = 0; j < 26; j++) {
                if (pCount[j] != sCount[j]) { match = false; break; }
            }
            if (match) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}