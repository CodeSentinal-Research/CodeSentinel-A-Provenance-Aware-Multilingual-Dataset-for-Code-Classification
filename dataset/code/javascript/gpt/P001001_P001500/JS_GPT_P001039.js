// P001039 - Furthest Reachable Building
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    let bricks = parseInt(input[1], 10);
    const ladders = parseInt(input[2], 10);
    const heights = [];
    let ptr = 3;
    for (let i = 0; i < n; i++) heights.push(parseInt(input[ptr++], 10));
    const ladderClimbs = [];
    for (let i = 0; i < n - 1; i++) {
        const diff = heights[i + 1] - heights[i];
        if (diff > 0) {
            let low = 0, high = ladderClimbs.length;
            while (low < high) {
                const mid = (low + high) >> 1;
                if (ladderClimbs[mid] < diff) low = mid + 1;
                else high = mid;
            }
            ladderClimbs.splice(low, 0, diff);
            if (ladderClimbs.length > ladders) {
                bricks -= ladderClimbs.shift();
            }
            if (bricks < 0) {
                console.log(i);
                return;
            }
        }
    }
    console.log(n - 1);
}

main();
