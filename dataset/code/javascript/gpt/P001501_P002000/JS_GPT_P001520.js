// P001520 - Max Chunks to Make Sorted
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[1 + i], 10));
    let chunks = 0, maxVal = 0;
    for (let i = 0; i < n; i++) {
        maxVal = Math.max(maxVal, arr[i]);
        if (maxVal === i) chunks++;
    }
    console.log(chunks);
}

main();
