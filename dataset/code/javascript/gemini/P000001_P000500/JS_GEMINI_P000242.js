function countZeroes(A, N) {
    let r = 0, c = N - 1;
    let count = 0;

    while (r < N && c >= 0) {
        if (A[r][c] === 0) {
            count += (c + 1);
            r++;
        } else {
            c--;
        }
    }
    return count;
}

module.exports = { countZeroes };