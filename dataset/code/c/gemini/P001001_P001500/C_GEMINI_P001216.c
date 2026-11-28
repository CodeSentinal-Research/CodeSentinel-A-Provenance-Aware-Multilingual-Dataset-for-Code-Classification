#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int mctFromLeafValues(int* arr, int arrSize) {
    int res = 0;
    int stack[arrSize + 2];
    int top = 0;
    stack[top++] = INT_MAX;

    for (int i = 0; i < arrSize; i++) {
        int x = arr[i];
        while (stack[top - 1] <= x) {
            int mid = stack[--top];
            res += mid * MIN(stack[top - 1], x);
        }
        stack[top++] = x;
    }
    while (top > 2) {
        int mid = stack[--top];
        res += mid * stack[top - 1];
    }
    return res;
}