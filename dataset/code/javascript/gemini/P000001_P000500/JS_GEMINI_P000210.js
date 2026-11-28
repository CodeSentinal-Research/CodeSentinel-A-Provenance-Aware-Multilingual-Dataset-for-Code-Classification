function commonElements(A, B, C) {
    let i = 0, j = 0, k = 0;
    const res = [];

    while (i < A.length && j < B.length && k < C.length) {
        if (A[i] === B[j] && B[j] === C[k]) {
            if (!res.length || res[res.length - 1] !== A[i]) {
                res.push(A[i]);
            }
            i++; j++; k++;
        } else if (A[i] < B[j]) {
            i++;
        } else if (B[j] < C[k]) {
            j++;
        } else {
            k++;
        }
    }
    return res;
}

module.exports = { commonElements };