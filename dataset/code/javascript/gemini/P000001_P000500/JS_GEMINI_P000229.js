function rowWithMax1s(arr, n, m) {
    let r = 0, c = m - 1;
    let maxRow = -1;

    while (r < n && c >= 0) {
        if (arr[r][c] === 1) {
            maxRow = r;
            c--;
        } else {
            r++;
        }
    }
    return maxRow;
}

module.exports = { rowWithMax1s };