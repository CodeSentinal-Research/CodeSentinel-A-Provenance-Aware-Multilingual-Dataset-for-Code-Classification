#include <stdlib.h>
#include <stdbool.h>

bool hasOnlyOneChild(int* preorder, int preorderSize) {
    for (int i = 0; i < preorderSize - 1; i++) {
        int nextDiff = preorder[i] - preorder[i + 1];
        int lastDiff = preorder[i] - preorder[preorderSize - 1];
        if ((long long)nextDiff * lastDiff < 0) return false;
    }
    return true;
}