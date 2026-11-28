#include <stdbool.h>

bool canThreePartsEqualSum(int* arr, int arrSize) {
    int total = 0;
    for (int i = 0; i < arrSize; i++) total += arr[i];
    if (total % 3 != 0) return false;

    int target = total / 3;
    int curSum = 0, count = 0;

    for (int i = 0; i < arrSize; i++) {
        curSum += arr[i];
        if (curSum == target) {
            count++;
            curSum = 0;
        }
    }
    return count >= 3;
}