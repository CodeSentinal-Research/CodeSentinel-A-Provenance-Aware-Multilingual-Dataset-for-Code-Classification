int maxRepeating(int* arr, int n, int k) {
    for (int i = 0; i < n; i++) {
        arr[arr[i] % k] += k;
    }

    int maxVal = arr[0], result = 0;
    for (int i = 1; i < k; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            result = i;
        }
    }
    return result;
}