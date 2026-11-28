// P001111 - Snake and Ladder Minimum Dice Throws
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const board = Array.from({ length: 31 }, () => -1);
    let ptr = 1;
    for (let i = 0; i < n; i++) {
        const src = parseInt(input[ptr++], 10);
        const dest = parseInt(input[ptr++], 10);
        board[src] = dest;
    }
    const visited = new Array(31).fill(false);
    const queue = [{ v: 1, dist: 0 }];
    visited[1] = true;
    while (queue.length > 0) {
        const { v, dist } = queue.shift();
        if (v === 30) {
            console.log(dist);
            return;
        }
        for (let dice = 1; dice <= 6; dice++) {
            const nextV = v + dice;
            if (nextV <= 30) {
                const finalPos = board[nextV] !== -1 ? board[nextV] : nextV;
                if (!visited[finalPos]) {
                    visited[finalPos] = true;
                    queue.push({ v: finalPos, dist: dist + 1 });
                }
            }
        }
    }
    console.log(-1);
}

main();
