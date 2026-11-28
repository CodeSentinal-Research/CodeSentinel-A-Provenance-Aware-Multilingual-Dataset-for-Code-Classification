// P001126 - Path With Minimum Effort
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const r = parseInt(input[0], 10);
    const c = parseInt(input[1], 10);
    let ptr = 2;
    const heights = [];
    for (let i = 0; i < r; i++) {
        const row = [];
        for (let j = 0; j < c; j++) row.push(parseInt(input[ptr++], 10));
        heights.push(row);
    }
    const effort = Array.from({ length: r }, () => new Array(c).fill(Infinity));
    effort[0][0] = 0;
    const pq = [{ x: 0, y: 0, d: 0 }];
    const dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]];
    while (pq.length > 0) {
        pq.sort((a, b) => a.d - b.d);
        const { x, y, d } = pq.shift();
        if (x === r - 1 && y === c - 1) {
            console.log(d);
            return;
        }
        if (d > effort[x][y]) continue;
        for (const [dx, dy] of dirs) {
            const nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                const newEffort = Math.max(d, Math.abs(heights[x][y] - heights[nx][ny]));
                if (newEffort < effort[nx][ny]) {
                    effort[nx][ny] = newEffort;
                    pq.push({ x: nx, y: ny, d: newEffort });
                }
            }
        }
    }
    console.log(0);
}

main();
