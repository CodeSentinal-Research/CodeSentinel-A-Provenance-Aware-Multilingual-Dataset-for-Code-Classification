#include <stdio.h>
#define MAX_N 100005
int vals[MAX_N];
int main() {
    int size;
    if (scanf("%d", &size) == 1) {
        for (int i = 0; i < size; i++) scanf("%d", &vals[i]);
        int n; scanf("%d", &n);
        if (n >= 1 && n <= size) printf("%d\n", vals[n - 1]);
        else printf("-1\n");
    }
    return 0;
}