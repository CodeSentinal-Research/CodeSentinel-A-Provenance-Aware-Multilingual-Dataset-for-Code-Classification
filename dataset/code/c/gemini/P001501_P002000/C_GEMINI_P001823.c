#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool verifyPostorder(int* postorder, int postorderSize) {
    int* stack = (int*)malloc(postorderSize * sizeof(int));
    int top = -1;
    int high = INT_MAX;

    for (int i = postorderSize - 1; i >= 0; i--) {
        int p = postorder[i];
        if (p > high) {
            free(stack);
            return false;
        }
        while (top >= 0 && p < stack[top]) {
            high = stack[top--];
        }
        stack[++top] = p;
    }
    free(stack);
    return true;
}