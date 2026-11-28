function findFirstIndex(N, arr, target) {
    for (let i = 0; i < N; i++) {
        if (arr[i] > target) {
            return i;
        }
    }
    return -1;
}