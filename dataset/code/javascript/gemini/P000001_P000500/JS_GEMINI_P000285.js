function isSubsequence(A, B) {
    let i = 0, j = 0;
    while (i < A.length && j < B.length) {
        if (A[i] === B[j]) i++;
        j++;
    }
    return i === A.length;
}

module.exports = { isSubsequence };