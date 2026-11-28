Here is a JavaScript code snippet that fulfills the problem requirements:

function matrixCells(rows, cols, rCenter, cCenter) {
    const res = [];
    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            res.push({r, c, distance: Math.abs(r - rCenter) + Math.abs(c - cCenter)});
        }
    }
    res.sort((a, b) => a.distance - b.distance);
    return res.map(cell => [cell.r, cell.c]);
}
In this code, we first generate all cells in the matrix with their coordinates and Manhattan distances from the starting cell. Then we sort the cells by their distance and return the cell coordinates.

Note: This code assumes the input values are valid (i.e., 1 <= rows, cols <= 100) and the starting cell (rCenter, cCenter) is within the matrix dimensions.

Also, it's worth mentioning that this code is not optimal for large matrix sizes due to the sorting step. If you want a more optimized solution for larger matrices, you would need to use a more efficient sorting algorithm or use a data structure that can quickly access the minimum distance cell.