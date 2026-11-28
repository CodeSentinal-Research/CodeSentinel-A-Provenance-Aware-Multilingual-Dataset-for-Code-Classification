#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;  // write through pointer
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));  // write through pointer
    int** triangle = (int**)malloc(numRows * sizeof(int*));

    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));
        triangle[i][0] = triangle[i][i] = 1;
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    return triangle;
}
