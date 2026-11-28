long long sumEvenNumbers(int n) {
    if (n < 2) return 0;
    long long k = n / 2;
    return k * (k + 1);
}
