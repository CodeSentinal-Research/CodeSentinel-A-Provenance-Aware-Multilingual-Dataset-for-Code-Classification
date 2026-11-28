#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minCut(char* s) {
    int n = strlen(s);
    int cuts[n];
    for (int i = 0; i < n; i++) cuts[i] = i;

    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            cuts[r] = (l == 0) ? 0 : MIN(cuts[r], cuts[l - 1] + 1);
            l--; r++;
        }
        l = i; r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            cuts[r] = (l == 0) ? 0 : MIN(cuts[r], cuts[l - 1] + 1);
            l--; r++;
        }
    }
    return cuts[n - 1];
}