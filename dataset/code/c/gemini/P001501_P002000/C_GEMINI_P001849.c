#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int getHeightArr(int* arr, int size) {
    if (size <= 0) return 0;
    int root = arr[0];
    int left[1000], right[1000];
    int lSize = 0, rSize = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] < root) left[lSize++] = arr[i];
        else right[rSize++] = arr[i];
    }
    return 1 + MAX(getHeightArr(left, lSize), getHeightArr(right, rSize));
}

int heightOfBST(int* preorder, int preorderSize) {
    return getHeightArr(preorder, preorderSize);
}