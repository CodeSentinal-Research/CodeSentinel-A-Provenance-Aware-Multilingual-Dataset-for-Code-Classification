#include <stdio.h>
#include <string.h>
#define MAX_N 10005
char events[MAX_N][64], dates[MAX_N][64];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%63s %63s", events[i], dates[i]);
        char target_date[64];
        scanf("%63s", target_date);
        for (int i = 0; i < n; i++) if (strcmp(dates[i], target_date) == 0) printf("%s\n", events[i]);
    }
    return 0;
}