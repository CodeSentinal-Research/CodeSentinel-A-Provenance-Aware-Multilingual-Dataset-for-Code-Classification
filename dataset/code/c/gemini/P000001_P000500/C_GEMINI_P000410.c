#include <stdio.h>
#include <string.h>
#define MAX_N 10005
char products[MAX_N][64];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%63s", products[i]);
        char suffix[64];
        scanf("%63s", suffix);
        int slen = strlen(suffix);
        for (int i = 0; i < n; i++) {
            int plen = strlen(products[i]);
            if (plen >= slen && strcmp(products[i] + plen - slen, suffix) == 0) printf("%s\n", products[i]);
        }
    }
    return 0;
}