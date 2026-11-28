// P001230 - Out of Boundary Paths
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const reqs = [];
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        reqs.push([u, v]);
    }
    let maxAchieved = 0;
    for (let mask = 0; mask < (1 << m); mask++) {
        const net = new Array(n).fill(0);
        let count = 0;
        for (let i = 0; i < m; i++) {
            if (mask & (1 << i)) {
                net[reqs[i][0]]--;
                net[reqs[i][1]]++;
                count++;
            }
        }
        let balanced = true;
        for (let i = 0; i < n; i++) {
            if (net[i] !== 0) { balanced = false; break; }
        }
        if (balanced && count > maxAchieved) maxAchieved = count;
    }
    console.log(maxAchieved);
}

main();
