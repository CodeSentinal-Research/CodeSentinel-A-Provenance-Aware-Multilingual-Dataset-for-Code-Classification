#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct { int coeff, exp; } Term;
Term poly[1005];
int size = 0;
int cmp(const void* a, const void* b) { return ((Term*)b)->exp - ((Term*)a)->exp; }
int main() {
    int q;
    if (scanf("%d", &q) == 1) {
        while (q--) {
            char cmd[32]; scanf("%31s", cmd);
            if (strcmp(cmd, "insert") == 0) {
                int c, e; scanf("%d %d", &c, &e);
                int found = -1;
                for (int i = 0; i < size; i++) if (poly[i].exp == e) { found = i; break; }
                if (found != -1) {
                    poly[found].coeff += c;
                    if (poly[found].coeff == 0) {
                        for (int i = found; i < size - 1; i++) poly[i] = poly[i+1];
                        size--;
                    }
                } else {
                    poly[size].coeff = c; poly[size].exp = e; size++;
                }
                qsort(poly, size, sizeof(Term), cmp);
            } else if (strcmp(cmd, "delete") == 0) {
                int e; scanf("%d", &e);
                int found = -1;
                for (int i = 0; i < size; i++) if (poly[i].exp == e) { found = i; break; }
                if (found != -1) {
                    for (int i = found; i < size - 1; i++) poly[i] = poly[i+1];
                    size--;
                }
            } else if (strcmp(cmd, "evaluate") == 0) {
                int x; scanf("%d", &x);
                long long ans = 0;
                for (int i = 0; i < size; i++) ans += poly[i].coeff * (long long)pow(x, poly[i].exp);
                printf("%lld\n", ans);
            } else if (strcmp(cmd, "display") == 0) {
                if (size == 0) {
                    printf("0\n");
                } else {
                    for (int i = 0; i < size; i++) {
                        if (i > 0) printf(" + ");
                        if (poly[i].exp > 0) printf("%dx^%d", poly[i].coeff, poly[i].exp);
                        else printf("%d", poly[i].coeff);
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}