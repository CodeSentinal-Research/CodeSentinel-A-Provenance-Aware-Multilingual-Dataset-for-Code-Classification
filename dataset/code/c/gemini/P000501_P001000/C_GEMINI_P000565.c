#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct { int r, c, dist; } Cell;
int cmp(const void* a, const void* b) {
    return ((Cell*)a)->dist - ((Cell*)b)->dist;
}
Cell cells[100005];
int main() {
    int rows, cols, r0, c0;
    if (scanf("%d %d %d %d", &rows, &cols, &r0, &c0) == 4) {
        int cnt = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cells[cnt].r = r;
                cells[cnt].c = c;
                cells[cnt].dist = abs(r - r0) + abs(c - c0);
                cnt++;
            }
        }
        qsort(cells, cnt, sizeof(Cell), cmp);
        for (int i = 0; i < cnt; i++) {
            printf("[%d,%d]%s", cells[i].r, cells[i].c, i == cnt - 1 ? "" : " ");
        }
        printf("\n");
    }
    return 0;
}