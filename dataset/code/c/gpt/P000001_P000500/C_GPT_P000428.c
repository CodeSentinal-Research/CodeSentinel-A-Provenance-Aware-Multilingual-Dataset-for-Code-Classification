#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXN 1005
#define MAXS 4096

static void print_ints(long long a[], int n) {
    for (int i = 0; i < n; i++) printf("%lld%s", a[i], i + 1 == n ? "\n" : " ");
    if (n == 0) printf("\n");
}

static int cmp_ll(const void *x, const void *y) {
    long long a = *(const long long *)x, b = *(const long long *)y;
    return (a > b) - (a < b);
}

static long long gcd_ll(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) { long long t = a % b; a = b; b = t; }
    return a;
}

/* Search Events Happening Today */
int main(void) {
    int n; if (scanf("%d", &n) != 1) return 0;
    char rec[MAXN][MAXS], key[MAXS]; getchar();
    for (int i = 0; i < n; i++) fgets(rec[i], MAXS, stdin);
    if (!fgets(key, MAXS, stdin)) key[0] = '\0';
    key[strcspn(key, "\r\n")] = '\0';
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(rec[i], key) != NULL) { fputs(rec[i], stdout); found = 1; }
    }
    if (!found) printf("Record Not Found\n");

    return 0;
}
