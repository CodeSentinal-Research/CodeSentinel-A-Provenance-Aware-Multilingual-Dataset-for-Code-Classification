#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int memo[100][100][100];

int dp_boxes(int* boxes, int l, int r, int k) {
    if (l > r) return 0;
    while (r > l && boxes[r] == boxes[r - 1]) {
        r--;
        k++;
    }
    if (memo[l][r][k] > 0) return memo[l][r][k];

    int res = dp_boxes(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
    for (int i = l; i < r; i++) {
        if (boxes[i] == boxes[r]) {
            res = MAX(res, dp_boxes(boxes, i + 1, r - 1, 0) + dp_boxes(boxes, l, i, k + 1));
        }
    }
    return memo[l][r][k] = res;
}

int removeBoxes(int* boxes, int boxesSize) {
    memset(memo, 0, sizeof(memo));
    return dp_boxes(boxes, 0, boxesSize - 1, 0);
}