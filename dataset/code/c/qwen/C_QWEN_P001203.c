#include <stdio.h>
#include <stdlib.h>
struct Env { int w, h; };
int cmp(const void *a, const void *b) {
    struct Env *x = (struct Env*)a, *y = (struct Env*)b;
    if(x->w != y->w) return x->w - y->w;
    return y->h - x->h;
}
int main() {
    int n; scanf("%d", &n);
    struct Env e[n]; for(int i=0; i<n; i++) scanf("%d%d", &e[i].w, &e[i].h);
    qsort(e, n, sizeof(struct Env), cmp);
    int dp[n]; for(int i=0; i<n; i++) dp[i] = 1;
    int max_len = 1;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(e[i].w > e[j].w && e[i].h > e[j].h && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
        }
        if(dp[i] > max_len) max_len = dp[i];
    }
    printf("%d\n", max_len);
    return 0;
}
