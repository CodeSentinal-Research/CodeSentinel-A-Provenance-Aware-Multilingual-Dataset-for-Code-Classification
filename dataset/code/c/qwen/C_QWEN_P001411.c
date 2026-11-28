#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);
    int wins[100001] = {0}, losses[100001] = {0};
    int present[100001] = {0};
    
    for (int i = 0; i < m; i++) {
        int w, l;
        scanf("%d %d", &w, &l);
        wins[w]++;
        losses[l]++;
        present[w] = 1;
        present[l] = 1;
    }
    
    int first = 1;
    for (int i = 0; i <= 100000; i++) {
        if (present[i] && losses[i] == 0) {
            if (!first) printf(" ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("\n");
    
    first = 1;
    for (int i = 0; i <= 100000; i++) {
        if (present[i] && losses[i] == 1) {
            if (!first) printf(" ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
