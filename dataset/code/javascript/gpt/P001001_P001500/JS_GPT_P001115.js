// P001115 - Shortest Path in a Binary Matrix
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const grid = [];
    for (let i = 0; i < n; i++) {
        const row = [];
        for (let j = 0; j < n; j++) row.push(parseInt(input[ptr++], 10));
        grid.push(row);
    }
    if (grid[0][0] !== 0 || grid[n - 1][n - 1] !== 0) {
        console.log(-1);
        return;
    }
    const queue = [[0, 0, 1]];
    grid[0][0] = 1;
    const dirs = [[-1,-1],[-1,0],[-1,1],[0,-1],[0,1],[1,-1],[1,0],[1,1]];
    while (queue.length > 0) {
        const [x, y, dist] = queue.shift();
        if (x === n - 1 && y === n - 1) {
            console.log(dist);
            return;
        }
        for (const [dx, dy] of dirs) {
            const nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] === 0) {
                grid[nx][ny] = 1;
                queue.push([nx, ny, dist + 1]);
            }
        }
    }
    console.log(-1);
}

main();
