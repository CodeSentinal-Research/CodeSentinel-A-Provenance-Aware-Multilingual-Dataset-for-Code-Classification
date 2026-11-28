#include <stdio.h>
#include <stdlib.h>
struct Task { int actual, minimum; };
int cmp(const void *a, const void *b) {
    struct Task *x = (struct Task*)a, *y = (struct Task*)b;
    return (y->minimum - y->actual) - (x->minimum - x->actual);
}
int main() {
    int n; scanf("%d", &n);
    struct Task t[n]; for(int i=0; i<n; i++) scanf("%d%d", &t[i].actual, &t[i].minimum);
    qsort(t, n, sizeof(struct Task), cmp);
    long long energy = 0, curr = 0;
    for(int i=0; i<n; i++) {
        if(curr < t[i].minimum) { energy += t[i].minimum - curr; curr = t[i].minimum; }
        curr -= t[i].actual;
    }
    printf("%lld\n", energy);
    return 0;
}
