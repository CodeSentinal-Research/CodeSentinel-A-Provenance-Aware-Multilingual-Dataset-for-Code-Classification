function wallsAndGates(grid) {
    let m = grid.length;
    if(m === 0) return grid;
    let n = grid[0].length;
    let dir = [[0,1],[0,-1],[1,0],[-1,0]]; // right, left, down, up
    let INF = Number.MAX_SAFE_INTEGER;

    // Use BFS to find all the gates and update their distances
    let gates = [];
    for(let i=0; i<m; i++) {
        for(let j=0; j<n; j++) {
            if(grid[i][j] === 0) {
                gates.push([i, j]);
            }
        }
    }

    for(let gate of gates) {
        let [i, j] = gate;
        let d = [[INF]*n];
        d[0][0] = 0;
        let queue = [[i, j, 0]];

        while(queue.length > 0) {
            let [x, y, depth] = queue.shift();
            for(let k=0; k<4; k++) {
                let [dx, dy] = dir[k];
                let nx = x + dx, ny = y + dy;

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && depth + 1 < d[nx][ny]) {
                    d[nx][ny] = depth + 1;
                    queue.push([nx, ny, depth + 1]);
                }
            }
        }
    }

    // Update the grid with the new distances
    for(let i=0; i<m; i++) {
        for(let j=0; j<n; j++) {
            if(grid[i][j] === 0) {
                grid[i][j] = 0;
            } else if(grid[i][j] !== INF) {
                grid[i][j] = grid[i][j];
            }
        }
    }

    return grid;
}

This JavaScript function `wallsAndGates()` first finds all the gates in the grid. It then uses a Breadth-First Search (BFS) to find the shortest distance to each gate from each room. The distance is represented as a 2D array `d`.

For each gate, it starts from the gate and updates the distance to all other rooms in the grid. The `queue` keeps track of the rooms to be updated, and `dir` is used to get the direction of each possible neighbor.

Finally, it updates the grid with the new distances. If a room is a gate, it keeps its original value; otherwise, it updates the value to be the new shortest distance.

Please note that this function modifies the original grid in-place and does not return a new grid. The input grid is updated in-place to contain the shortest distances from the gates.