// P001278 - Max Chunks to Make Sorted II
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[1 + i], 10));
    const rMin = new Array(n + 1).fill(Infinity);
    for (let i = n - 1; i >= 0; i--) rMin[i] = Math.min(rMin[i + 1], arr[i]);
    let chunks = 0, lMax = -Infinity;
    for (let i = 0; i < n; i++) {
        lMax = Math.max(lMax, arr[i]);
        if (lMax <= rMin[i + 1]) chunks++;
    }
    console.log(chunks);
}

main();
