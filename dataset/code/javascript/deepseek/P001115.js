Here is a simple JavaScript code for finding the shortest path in a binary matrix:

function shortestPath(matrix) {
    const rows = matrix.length;
    const cols = matrix[0].length;
    const dp = Array.from(matrix, () => Array(cols).fill(Infinity));

    dp[0][0] = 0;
    const dir = [[1, 0], [-1, 0], [0, 1], [0, -1], [-1, -1], [-1, 1], [1, -1], [1, 1]]; // eight directions

    const getMinDistance = (x, y) => {
        let minDistance = Infinity;

        for (let i = 0; i < 8; i++) {
            const nx = x + dir[i][0];
            const ny = y + dir[i][1];

            if (nx < 0 || ny < 0 || nx >= rows || ny >= cols) continue;
            const newDistance = dp[nx][ny] + 1;

            if (newDistance < minDistance) minDistance = newDistance;
        }

        return minDistance;
    };

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            dp[i][j] = getMinDistance(i, j);
        }
    }

    if (dp[rows - 1][cols - 1] === Infinity) return -1;

    return dp[rows - 1][cols - 1];
}
This code uses a 2D Dynamic Programming (DP) approach. The `dp` array stores the minimum distance to reach the cell from the top-left cell. The `getMinDistance` function calculates the minimum distance to reach a cell in eight directions. If the distance is still Infinity, it means the cell is out of the matrix, so return -1.

Note that this code assumes that the input matrix is always valid. If the input matrix can be invalid (for example, if it has an odd number of rows), you should add error checking code to handle these cases.