#include <stdio.h>
#include <string.h>
#include <strings.h>
#define MAX_N 10005
char contacts[MAX_N][64];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%63s", contacts[i]);
        char target[64];
        scanf("%63s", target);
        for (int i = 0; i < n; i++) if (strcasecmp(contacts[i], target) == 0) printf("%s\n", contacts[i]);
    }
    return 0;
}