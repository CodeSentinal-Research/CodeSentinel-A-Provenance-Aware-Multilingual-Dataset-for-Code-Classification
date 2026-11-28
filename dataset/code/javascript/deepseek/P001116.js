Here's a JavaScript solution using Depth-First Search (DFS):

function surroundedRegions(grid) {
    if (!grid || !grid.length || !grid[0].length) return;

    let rows = grid.length;
    let cols = grid[0].length;
    let directions = [[0, 1], [0, -1], [1, 0], [-1, 0]];

    function dfs(i, j) {
        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] != 'O') {
            return;
        }

        grid[i][j] = 'T'; // mark as visited

        for (let d = 0; d < 4; d++) {
            dfs(i + directions[d][0], j + directions[d][1]);
        }
    }

    // find all 'O' cells and perform DFS from there
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (grid[i][j] == 'O') {
                dfs(i, j);
            }
        }
    }

    // convert 'T' back to 'O' and 'X' to 'X'
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (grid[i][j] == 'T') {
                grid[i][j] = 'O';
            } else if (grid[i][j] == 'X') {
                grid[i][j] = 'X';
            }
        }
    }
}

This code works by first finding all 'O' cells and running a DFS from there. In the DFS, we mark each cell as 'T' and then perform a depth-first search from there. After we're done, we convert all 'T' cells back to 'O' and all 'O' cells to 'X'.