#include <stdio.h>
int main() {
    int q; scanf("%d", &q);
    int stack_val[100001], stack_span[100001], top=-1;
    while(q--) {
        int price; scanf("%d", &price);
        int span=1;
        while(top>=0 && stack_val[top]<=price) { span+=stack_span[top]; top--; }
        stack_val[++top]=price;
        stack_span[top]=span;
        printf("%d\n", span);
    }
    return 0;
}
