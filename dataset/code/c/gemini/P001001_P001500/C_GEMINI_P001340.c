#include <limits.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int cmpDescCookies(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int ansCookie;

void backtrackCookies(int* cookies, int n, int idx, int children[], int k) {
    if (idx == n) {
        int maxCookie = 0;
        for (int i = 0; i < k; i++) maxCookie = MAX(maxCookie, children[i]);
        ansCookie = MIN(ansCookie, maxCookie);
        return;
    }

    int maxChild = 0;
    for (int i = 0; i < k; i++) maxChild = MAX(maxChild, children[i]);
    if (maxChild >= ansCookie) return;

    for (int i = 0; i < k; i++) {
        children[i] += cookies[idx];
        backtrackCookies(cookies, n, idx + 1, children, k);
        children[i] -= cookies[idx];
        if (children[i] == 0) break;
    }
}

int distributeCookies(int* cookies, int cookiesSize, int k) {
    qsort(cookies, cookiesSize, sizeof(int), cmpDescCookies);
    ansCookie = INT_MAX;
    int children[8] = {0};
    backtrackCookies(cookies, cookiesSize, 0, children, k);
    return ansCookie;
}