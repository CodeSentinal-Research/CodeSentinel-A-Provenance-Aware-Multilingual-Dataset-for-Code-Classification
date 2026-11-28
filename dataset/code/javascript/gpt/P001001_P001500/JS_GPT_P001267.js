// P001267 - Furthest Building You Can Reach
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
    const climbs = [];
    for (let i = 0; i < n - 1; i++) {
        const diff = heights[i + 1] - heights[i];
        if (diff > 0) {
            let low = 0, high = climbs.length;
            while (low < high) {
                const mid = (low + high) >> 1;
                if (climbs[mid] < diff) low = mid + 1;
                else high = mid;
            }
            climbs.splice(low, 0, diff);
            if (climbs.length > ladders) {
                bricks -= climbs.shift();
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
