#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestMountain(int* arr, int arrSize) {
    int ans = 0, base = 0;

    while (base < arrSize) {
        int end = base;
        if (end + 1 < arrSize && arr[end] < arr[end + 1]) {
            while (end + 1 < arrSize && arr[end] < arr[end + 1]) end++;
            if (end + 1 < arrSize && arr[end] > arr[end + 1]) {
                while (end + 1 < arrSize && arr[end] > arr[end + 1]) end++;
                ans = MAX(ans, end - base + 1);
            }
        }
        base = MAX(end, base + 1);
    }
    return ans;
}