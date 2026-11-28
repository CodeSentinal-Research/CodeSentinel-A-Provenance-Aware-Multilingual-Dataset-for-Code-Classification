int equilibriumPoint(long long* arr, int n) {
    long long totalSum = 0;
    for (int i = 0; i < n; i++) totalSum += arr[i];
    long long leftSum = 0;

    for (int i = 0; i < n; i++) {
        if (leftSum == totalSum - leftSum - arr[i]) return i + 1;
        leftSum += arr[i];
    }
    return -1;
}