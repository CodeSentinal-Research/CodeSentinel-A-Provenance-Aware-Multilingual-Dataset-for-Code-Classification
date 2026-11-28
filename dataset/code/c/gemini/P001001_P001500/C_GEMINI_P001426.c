#define MAX(a, b) ((a) > (b) ? (a) : (b))

int findLucky(int* arr, int arrSize) {
    int count[505] = {0};
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] <= 500) count[arr[i]]++;
    }

    int maxLucky = -1;
    for (int i = 1; i <= 500; i++) {
        if (count[i] == i) {
            maxLucky = MAX(maxLucky, i);
        }
    }
    return maxLucky;
}