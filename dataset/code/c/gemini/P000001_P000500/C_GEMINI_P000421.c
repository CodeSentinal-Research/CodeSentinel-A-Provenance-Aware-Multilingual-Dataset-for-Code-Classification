#include <stdio.h>
#include <string.h>
#define MAX_N 10005
char ids[MAX_N][64], exps[MAX_N][64];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%63s %63s", ids[i], exps[i]);
        char curr_date[64];
        scanf("%63s", curr_date);
        for (int i = 0; i < n; i++) if (strcmp(exps[i], curr_date) < 0) printf("%s\n", ids[i]);
    }
    return 0;
}