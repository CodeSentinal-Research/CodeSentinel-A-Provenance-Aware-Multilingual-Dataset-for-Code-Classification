#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxTurbulenceSize(int* arr, int arrSize) {
    int ans = 1, anchor = 0;

    for (int i = 1; i < arrSize; i++) {
        int c = (arr[i - 1] > arr[i]) - (arr[i - 1] < arr[i]);
        if (c == 0) {
            anchor = i;
        } else if (i == arrSize - 1 || c * ((arr[i] > arr[i + 1]) - (arr[i] < arr[i + 1])) != -1) {
            ans = MAX(ans, i - anchor + 1);
            anchor = i;
        }
    }
    return ans;
}