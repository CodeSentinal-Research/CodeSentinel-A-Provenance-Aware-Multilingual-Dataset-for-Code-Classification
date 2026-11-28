#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100005
char tokens[MAX_N][32];
int main() {
    int cnt = 0;
    while (scanf("%31s", tokens[cnt]) == 1) cnt++;
    if (cnt == 0) return 0;
    int start = 0;
    if (cnt > 1 && atoi(tokens[0]) == cnt - 1) start = 1;
    int total = cnt - start;
    // Calculate midpoint to prevent potential overflow
    int mid = (total + 1) / 2;
    for (int i = 0; i < mid; i++) printf("%s%s", tokens[start + i], i == mid - 1 ? "" : " ");
    printf("\n");
    for (int i = mid; i < total; i++) printf("%s%s", tokens[start + i], i == total - 1 ? "" : " ");
    printf("\n");
    return 0;
}