#include <stdio.h>
#define MAX_N 100005
int prices[MAX_N], spans[MAX_N];
int main() {
    int q;
    if (scanf("%d", &q) == 1) {
        int top = -1;
        while (q--) {
            int price;
            scanf("%d", &price);
            int span = 1;
            while (top >= 0 && prices[top] <= price) {
                span += spans[top--];
            }
            top++;
            prices[top] = price;
            spans[top] = span;
            printf("%d\n", span);
        }
    }
    return 0;
}