#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 10005
int nums[MAX_N];
int num_count = 0;
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
    int q;
    if (scanf("%d", &q) == 1) {
        while (q--) {
            char cmd[32];
            scanf("%31s", cmd);
            if (strcmp(cmd, "addNum") == 0) {
                int val; scanf("%d", &val);
                int found = 0;
                for (int i = 0; i < num_count; i++) {
                    if (nums[i] == val) { found = 1; break; }
                }
                if (!found) nums[num_count++] = val;
            } else if (strcmp(cmd, "getIntervals") == 0) {
                qsort(nums, num_count, sizeof(int), cmp);
                int first = 1;
                int start = -1, end = -1;
                for (int i = 0; i < num_count; i++) {
                    if (start == -1) {
                        start = end = nums[i];
                    } else if (nums[i] == end + 1) {
                        end = nums[i];
                    } else {
                        if (!first) printf(" ");
                        printf("[%d,%d]", start, end);
                        first = 0;
                        start = end = nums[i];
                    }
                }
                if (start != -1) {
                    if (!first) printf(" ");
                    printf("[%d,%d]", start, end);
                }
                printf("\n");
            }
        }
    }
    return 0;
}