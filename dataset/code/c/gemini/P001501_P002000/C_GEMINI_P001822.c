#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool verifyPreorder(int* preorder, int preorderSize) {
    int* stack = (int*)malloc(preorderSize * sizeof(int));
    int top = -1;
    int low = INT_MIN;

    for (int i = 0; i < preorderSize; i++) {
        int p = preorder[i];
        if (p < low) {
            free(stack);
            return false;
        }
        while (top >= 0 && p > stack[top]) {
            low = stack[top--];
        }
        stack[++top] = p;
    }
    free(stack);
    return true;
}