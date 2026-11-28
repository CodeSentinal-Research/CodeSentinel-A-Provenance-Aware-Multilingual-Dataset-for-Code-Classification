#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int size;
    if (scanf("%d", &size) == 1) {
        for (int i = 0; i < size; i++) scanf("%d", &vals[i]);
        int n; scanf("%d", &n);
        int rem = size - n, first = 1;
        for (int i = 0; i < size; i++) {
            if (i == rem) continue;
            if (!first) printf(" ");
            printf("%d", vals[i]);
            first = 0;
        }
        printf("\n");
    }
    return 0;
}