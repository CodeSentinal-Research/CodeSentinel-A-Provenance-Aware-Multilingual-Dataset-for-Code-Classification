Here is the JavaScript solution for the problem. I'm assuming that the forest is represented in a 2D array and the tree heights are stored in another 2D array.

function cutOffTree(forest) {
    const m = forest.length;
    const n = forest[0].length;
    const start = [0, 0];
    const end = [m - 1, n - 1];
    const map = {};
    const heap = [[forest[0][0], [start]]];
    let result = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i !== 0 || j !== 0) map[`${i}${j}`] = Infinity;
            if (forest[i][j] === 0) continue;
            const queue = [];
            queue.push([forest[i][j], i, j]);
            while (queue.length) {
                const [dist, x, y] = queue.shift();
                if (`${x}${y}` === `${end[0]}${end[1]}`) return dist;
                for (const [dx, dy] of [[0, 1], [0, -1], [1, 0], [-1, 0]]) {
                    const nx = x + dx, ny = y + dy;
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || forest[nx][ny] === undefined) continue;
                    const newDist = dist + 1;
                    if (newDist < map[`${nx}${ny}`]) {
                        map[`${nx}${ny}`] = newDist;
                        queue.push([newDist, nx, ny]);
                    }
                }
            }
        }
    }
    return -1;
}

This code uses a breadth-first search (BFS) algorithm to find the shortest path from the starting point to the end point in the forest. If a shorter path is found, it is added to the queue. If a path from the end to a cell (i, j) is found, the function returns the total steps required to reach this cell. If no path is found, it returns -1.