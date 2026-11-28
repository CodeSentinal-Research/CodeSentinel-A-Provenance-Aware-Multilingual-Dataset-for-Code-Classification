#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val, wt;
} Item;

int cmpItem(const void* a, const void* b) {
    double r1 = (double)((Item*)a)->val / ((Item*)a)->wt;
    double r2 = (double)((Item*)b)->val / ((Item*)b)->wt;
    if (r2 > r1) return 1;
    if (r2 < r1) return -1;
    return 0;
}

int main() {
    int n, w;
    if (scanf("%d %d", &n, &w) == 2) {
        Item* items = (Item*)malloc(n * sizeof(Item));
        for (int i = 0; i < n; i++) scanf("%d %d", &items[i].val, &items[i].wt);

        qsort(items, n, sizeof(Item), cmpItem);
        double totalVal = 0.0;
        int cap = w;

        for (int i = 0; i < n; i++) {
            if (cap >= items[i].wt) {
                totalVal += items[i].val;
                cap -= items[i].wt;
            } else {
                totalVal += (double)items[i].val * ((double)cap / items[i].wt);
                break;
            }
        }
        printf("%.6f\n", totalVal);
        free(items);
    }
    return 0;
}