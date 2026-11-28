#include <stdio.h>
#include <string.h>
#define MAX_N 100005
char num[MAX_N];
char st[MAX_N];
int main() {
    int k;
    if (scanf("%100004s %d", num, &k) == 2) {
        int top = -1;
        for (int i = 0; num[i]; i++) {
            while (k > 0 && top >= 0 && st[top] > num[i]) {
                top--;
                k--;
            }
            st[++top] = num[i];
        }
        while (k > 0 && top >= 0) { top--; k--; }
        st[top + 1] = '\0';
        int start = 0;
        while (st[start] == '0') start++;
        if (st[start] == '\0') printf("0\n");
        else printf("%s\n", st + start);
    }
    return 0;
}