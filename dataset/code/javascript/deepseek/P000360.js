function searchEven(N, arr) {
    if (N < 1 || N > 100000) {
        return "Invalid input";
    }

    for (let i = 0; i < N; i++) {
        if (arr[i] % 2 === 0) {
            return i;
        }
    }

    return -1;
}