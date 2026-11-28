// P001521 - Max Chunks to Make Sorted II
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[1 + i], 10));
    const leftMax = new Array(n);
    const rightMin = new Array(n + 1);
    leftMax[0] = arr[0];
    for (let i = 1; i < n; i++) leftMax[i] = Math.max(leftMax[i - 1], arr[i]);
    rightMin[n] = Infinity;
    for (let i = n - 1; i >= 0; i--) rightMin[i] = Math.min(rightMin[i + 1], arr[i]);
    let chunks = 0;
    for (let i = 0; i < n; i++) {
        if (leftMax[i] <= rightMin[i + 1]) chunks++;
    }
    console.log(chunks);
}

main();
