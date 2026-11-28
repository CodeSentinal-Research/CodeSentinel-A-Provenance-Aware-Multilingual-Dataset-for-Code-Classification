#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        int* u_arr = (int*)malloc(m * sizeof(int));
        int* v_arr = (int*)malloc(m * sizeof(int));
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u_arr[i], &v_arr[i]);
        }
        int target;
        scanf("%d", &target);
        int* neighbors = (int*)malloc(m * sizeof(int));
        int count = 0;
        for (int i = 0; i < m; i++) {
            if (u_arr[i] == target) neighbors[count++] = v_arr[i];
            else if (v_arr[i] == target) neighbors[count++] = u_arr[i];
        }
        qsort(neighbors, count, sizeof(int), cmp);
        for (int i = 0; i < count; i++) {
            printf("%d%s", neighbors[i], (i == count - 1 ? "" : " "));
        }
        printf("\n");
        free(u_arr);
        free(v_arr);
        free(neighbors);
    }
    return 0;
}