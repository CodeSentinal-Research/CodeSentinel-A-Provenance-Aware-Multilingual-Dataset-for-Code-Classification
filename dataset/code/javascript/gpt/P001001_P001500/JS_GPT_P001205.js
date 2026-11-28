// P001205 - Number of Longest Increasing Subsequences
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[1 + i], 10));
    let noDel = arr[0], oneDel = 0, maxAns = arr[0];
    for (let i = 1; i < n; i++) {
        const x = arr[i];
        oneDel = Math.max(noDel, oneDel + x);
        noDel = Math.max(x, noDel + x);
        maxAns = Math.max(maxAns, noDel, oneDel);
    }
    console.log(maxAns);
}

main();
