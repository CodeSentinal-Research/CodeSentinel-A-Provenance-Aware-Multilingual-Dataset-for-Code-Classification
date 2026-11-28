// Helper function to evaluate findtheprefixcommonarray for problem constraints.
function findThePrefixCommonArray(A, B) {
    const n = A.length;
    const res = new Array(n).fill(0);
    const count = new Array(n + 1).fill(0);
    let common = 0;

    for (let i = 0; i < n; i++) {
        if (++count[A[i]] === 2) common++;
        if (++count[B[i]] === 2) common++;
        res[i] = common;
    }
    return res;
}

module.exports = { findThePrefixCommonArray };