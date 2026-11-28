#include <stdio.h>
#include <stdlib.h>

struct Meeting {
    int start;
    int end;
};

int cmp(const void *a, const void *b) {
    struct Meeting *x = (struct Meeting *)a;
    struct Meeting *y = (struct Meeting *)b;
    return x->end - y->end;
}

int main() {
    int n;
    scanf("%d", &n);
    struct Meeting m[n];
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &m[i].start, &m[i].end);
    }
    qsort(m, n, sizeof(struct Meeting), cmp);
    int count = 1;
    int end = m[0].end;
    for (int i = 1; i < n; i++) {
        if (m[i].start >= end) {
            count++;
            end = m[i].end;
        }
    }
    printf("%d\n", count);
    return 0;
}
