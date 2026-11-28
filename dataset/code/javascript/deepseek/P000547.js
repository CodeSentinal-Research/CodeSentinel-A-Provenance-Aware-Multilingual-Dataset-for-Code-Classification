Here is the JavaScript code that solves the problem:

function maxTimeToVisitSafely(m, n, grid) {
    if (grid[m-1][n-1] === 2) return -1;
    let queue = [[m-1, n-1]];
    let visited = Array(m).fill(0).map(() => Array(n).fill(Infinity));
    visited[m-1][n-1] = 0;
    let dx = [-1, 1, 0, 0];
    let dy = [0, 0, -1, 1];

    while(queue.length > 0) {
        let cell = queue.shift();
        for(let i = 0; i < 4; i++) {
            let x = cell[0] + dx[i];
            let y = cell[1] + dy[i];
            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] === 0 && visited[x][y] > visited[cell[0]][cell[1]] + 1) {
                queue.push([x, y]);
                visited[x][y] = visited[cell[0]][cell[1]] + 1;
            }
        }
    }
    return visited[0][0];
}

This code uses a breadth-first search (BFS) approach to find the maximum time to visit the cells. The queue is initially set with the starting cell, and all the distances from the starting cell are initialized as Infinity (a large value). The BFS is done in the following steps:

- For each cell in the queue, we check all its adjacent cells. If a cell is not visited yet and it is an empty cell, we add it to the queue and update its distance.
- If we reach the destination, we return the distance. If we cannot reach the destination, we return -1.

This solution assumes that the grid is always a valid input. If the grid can be invalid, you should add checks for invalid input.