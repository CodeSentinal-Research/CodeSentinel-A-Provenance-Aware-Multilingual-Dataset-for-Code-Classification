#include <stdio.h>
#define MAX_C 1005
int heights[MAX_C];
int st[MAX_C];
int largestArea(int c) {
    heights[c] = 0;
    int top = 0;
    st[0] = -1;
    int max_area = 0;
    for (int i = 0; i <= c; i++) {
        while (top > 0 && heights[st[top]] >= heights[i]) {
            int h = heights[st[top--]];
            int w = i - st[top] - 1;
            if (h * w > max_area) max_area = h * w;
        }
        st[++top] = i;
    }
    return max_area;
}
int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) == 2) {
        int max_area = 0;
        for (int j = 0; j < c; j++) heights[j] = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int val; scanf("%d", &val);
                heights[j] = (val == 1) ? heights[j] + 1 : 0;
            }
            int area = largestArea(c);
            if (area > max_area) max_area = area;
        }
        printf("%d\n", max_area);
    }
    return 0;
}