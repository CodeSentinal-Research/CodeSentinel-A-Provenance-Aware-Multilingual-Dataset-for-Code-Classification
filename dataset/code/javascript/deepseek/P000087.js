function findSum(N) {
    if (N < 1 || N > 10e9 || !Number.isInteger(N)) {
        throw new Error('Invalid input. N must be a positive integer up to 10^9.');
    }

    return N * (N + 1) / 2;
}