Here is the JavaScript code for the problem:

function min_moves(n, grid) {
    const directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]; // right, down, left, up
    const rows = n;
    const cols = n;
    const inf = Math.pow(10, 9);
    const visited = new Array(rows + 1).fill(0).map(() => new Array(cols + 1).fill(-1));
    let [snakeX, snakeY] = [0, 0];
    let [targetX, targetY] = [rows - 1, cols - 1];

    function dfs(x, y, dir, steps) {
        if (x == targetX && y == targetY) {
            return steps;
        }
        for (let i = 0; i < 4; i++) {
            let dx = x + directions[i][0], dy = y + directions[i][1];
            if (dx < 0 || dx >= rows || dy < 0 || dy >= cols || visited[dx][dy] != -1) {
                continue;
            }
            if (grid[dx][dy] == 1) {
                continue;
            }
            visited[dx][dy] = steps + 1;
            let ret = dfs(dx, dy, i, steps + 1);
            if (ret != -1) {
                return ret;
            }
            visited[dx][dy] = -1;
        }
        if (dir != 0) {
            let ndir = (dir + 1) % 4;
            let nx = x + directions[ndir][0], ny = y + directions[ndir][1];
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && visited[nx][ny] == -1 && grid[nx][ny] == 0) {
                visited[nx][ny] = steps + 1;
                let ret = dfs(nx, ny, ndir, steps + 1);
                if (ret != -1) {
                    return ret;
                }
                visited[nx][ny] = -1;
            }
        }
        return -1;
    }

    if (grid[snakeX][snakeY] == 1) {
        return -1;
    }
    visited[snakeX][snakeY] = 0;
    let ret = dfs(snakeX, snakeY, 0, 0);
    return ret;
}

This code uses depth-first search (DFS) to find the shortest path from the source to the target. It maintains a visited array to record the visited cells and directions. The dfs function is called recursively to try all possible moves (right, down, left, up) of the snake. If the target cell is reached, it returns the number of moves. If the current cell is an obstacle or the snake hits the target, it continues to the next cell. If the snake hits the target and it's not possible to reach, it returns -1.

The time complexity is O(n^2) because there are 4 directions for each cell and for each direction, there are at most n^2 steps. The space complexity is O(n^2) due to the visited array.