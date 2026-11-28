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

/* Remove All Vowels */
int main(void) {
    char s[MAXS], t[MAXS]; s[0] = t[0] = '\0';
    scanf(" %4095[^\n]", s);
    if (strstr("A string S.", "Two strings")) scanf(" %4095[^\n]", t);
    int len = (int)strlen(s);
    int c=0; for(int i=0;s[i];i++){ char ch=tolower((unsigned char)s[i]); if(strchr("aeiou",ch)) c++; } printf("%d\n", c);

    return 0;
}
