#include <stdio.h>
#include <string.h>

#define MAX_N 10005
char titles[MAX_N][64];
int years[MAX_N];

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%63s %d", titles[i], &years[i]);
        }
        int min_year;
        scanf("%d", &min_year);
        for (int i = 0; i < n; i++) {
            if (years[i] > min_year) {
                printf("%s\n", titles[i]);
            }
        }
    }
    return 0;
}