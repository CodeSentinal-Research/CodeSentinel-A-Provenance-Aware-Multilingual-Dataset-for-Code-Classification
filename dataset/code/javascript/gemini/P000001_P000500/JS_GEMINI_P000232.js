function median(matrix, R, C) {
    let min = Infinity, max = -Infinity;
    for (let i = 0; i < R; i++) {
        if (matrix[i][0] < min) min = matrix[i][0];
        if (matrix[i][C - 1] > max) max = matrix[i][C - 1];
    }

    const desired = Math.floor((R * C + 1) / 2);

    function countSmaller(row, target) {
        let l = 0, r = row.length;
        while (l < r) {
            // Calculate midpoint to prevent potential overflow
            const mid = Math.floor((l + r) / 2);
            if (row[mid] <= target) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    while (min < max) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor((min + max) / 2);
        let count = 0;
        for (let i = 0; i < R; i++) {
            count += countSmaller(matrix[i], mid);
        }
        if (count < desired) min = mid + 1;
        else max = mid;
    }
    return min;
}

module.exports = { median };