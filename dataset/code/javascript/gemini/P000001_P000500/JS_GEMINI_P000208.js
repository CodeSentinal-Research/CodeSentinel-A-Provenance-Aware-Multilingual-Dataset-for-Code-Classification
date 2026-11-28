function findDiagonalOrder(mat) {
    if (!mat.length || !mat[0].length) return [];
    const m = mat.length, n = mat[0].length;
    const res = [];

    for (let d = 0; d < m + n - 1; d++) {
        const temp = [];
        let r = d < n ? 0 : d - n + 1;
        let c = d < n ? d : n - 1;

        while (r < m && c >= 0) {
            temp.push(mat[r][c]);
            r++;
            c--;
        }

        if (d % 2 === 0) {
            res.push(...temp.reverse());
        } else {
            res.push(...temp);
        }
    }
    return res;
}

module.exports = { findDiagonalOrder };