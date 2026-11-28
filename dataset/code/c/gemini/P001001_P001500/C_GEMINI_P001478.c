#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int** intervalIntersection(int** firstList, int firstListSize, int* firstListColSize, int** secondList, int secondListSize, int* secondListColSize, int* returnSize, int** returnColumnSizes) {
    int maxCapacity = firstListSize + secondListSize;
    int** res = (int**)malloc(maxCapacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxCapacity * sizeof(int));
    int count = 0;

    int i = 0, j = 0;
    while (i < firstListSize && j < secondListSize) {
        int lo = MAX(firstList[i][0], secondList[j][0]);
        int hi = MIN(firstList[i][1], secondList[j][1]);

        if (lo <= hi) {
            res[count] = (int*)malloc(2 * sizeof(int));
            res[count][0] = lo;
            res[count][1] = hi;
            (*returnColumnSizes)[count] = 2;
            count++;
        }

        if (firstList[i][1] < secondList[j][1]) i++;
        else j++;
    }

    *returnSize = count;
    return res;
}