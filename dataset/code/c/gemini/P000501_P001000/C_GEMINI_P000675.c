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
    for (int i = cnt - 1; i >= start; i--) {
        printf("%s%s", tokens[i], i == start ? "" : " ");
    }
    printf("\n");
    return 0;
}