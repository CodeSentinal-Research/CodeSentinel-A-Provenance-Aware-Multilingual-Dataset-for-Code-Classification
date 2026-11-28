// P001114 - Rotten Oranges
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const r = parseInt(input[0], 10);
    const c = parseInt(input[1], 10);
    let ptr = 2;
    const grid = [];
    const queue = [];
    let fresh = 0;
    for (let i = 0; i < r; i++) {
        const row = [];
        for (let j = 0; j < c; j++) {
            const val = parseInt(input[ptr++], 10);
            row.push(val);
            if (val === 2) queue.push([i, j, 0]);
            else if (val === 1) fresh++;
        }
        grid.push(row);
    }
    let maxTime = 0;
    const dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]];
    while (queue.length > 0) {
        const [x, y, time] = queue.shift();
        maxTime = Math.max(maxTime, time);
        for (const [dx, dy] of dirs) {
            const nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] === 1) {
                grid[nx][ny] = 2;
                fresh--;
                queue.push([nx, ny, time + 1]);
            }
        }
    }
    console.log(fresh === 0 ? maxTime : -1);
}

main();
