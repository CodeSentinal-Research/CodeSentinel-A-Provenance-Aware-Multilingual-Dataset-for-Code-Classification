#include <stdio.h>
#include <stdlib.h>

struct Project {
    int capital;
    int profit;
};

int cmp_capital(const void *a, const void *b) {
    struct Project *x = (struct Project *)a;
    struct Project *y = (struct Project *)b;
    return x->capital - y->capital;
}

int cmp_profit(const void *a, const void *b) {
    struct Project *x = (struct Project *)a;
    struct Project *y = (struct Project *)b;
    return y->profit - x->profit;
}

int main() {
    int n, k;
    long long initial_capital;
    scanf("%d%d%lld", &n, &k, &initial_capital);
    struct Project p[n];
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &p[i].capital, &p[i].profit);
    }
    qsort(p, n, sizeof(struct Project), cmp_capital);
    long long capital = initial_capital;
    int idx = 0;
    for (int i = 0; i < k; i++) {
        while (idx < n && p[idx].capital <= capital) {
            idx++;
        }
        int max_profit = -1;
        int max_idx = -1;
        for (int j = 0; j < idx; j++) {
            if (p[j].profit > max_profit) {
                max_profit = p[j].profit;
                max_idx = j;
            }
        }
        if (max_idx == -1) break;
        capital += max_profit;
        p[max_idx].profit = -1;
    }
    printf("%lld\n", capital);
    return 0;
}
