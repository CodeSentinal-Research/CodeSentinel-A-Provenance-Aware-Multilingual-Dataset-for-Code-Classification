// P001185 - Delete and Earn
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const points = new Array(10001).fill(0);
    for (let i = 0; i < n; i++) {
        const val = parseInt(input[1 + i], 10);
        points[val] += val;
    }
    let take = 0, skip = 0;
    for (let i = 0; i <= 10000; i++) {
        const takeI = skip + points[i];
        const skipI = Math.max(skip, take);
        take = takeI;
        skip = skipI;
    }
    console.log(Math.max(take, skip));
}

main();
