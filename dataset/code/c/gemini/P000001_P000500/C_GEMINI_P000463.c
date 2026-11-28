#include <stdio.h>
#define MAX_N 100005
int a[MAX_N], b[MAX_N], c[MAX_N];
int main() {
    int n1, n2, n3;
    if (scanf("%d %d %d", &n1, &n2, &n3) == 3) {
        for (int i = 0; i < n1; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n2; i++) scanf("%d", &b[i]);
        for (int i = 0; i < n3; i++) scanf("%d", &c[i]);
        int i = 0, j = 0, k = 0, count = 0, last = -1000000000;
        while (i < n1 && j < n2 && k < n3) {
            if (a[i] == b[j] && b[j] == c[k]) {
                if (count == 0 || a[i] != last) {
                    if (count > 0) printf(" ");
                    printf("%d", a[i]);
                    last = a[i];
                    count++;
                }
                i++; j++; k++;
            } else if (a[i] < b[j]) i++;
            else if (b[j] < c[k]) j++;
            else k++;
        }
        if (count == 0) printf("-1");
        printf("\n");
    }
    return 0;
}