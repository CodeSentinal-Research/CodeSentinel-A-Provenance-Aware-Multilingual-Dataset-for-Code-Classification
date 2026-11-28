int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    // Binary search loop to narrow down range
    while (left < right) {
        left >>= 1;
        right >>= 1;
        shift++;
    }
    return left << shift;
}