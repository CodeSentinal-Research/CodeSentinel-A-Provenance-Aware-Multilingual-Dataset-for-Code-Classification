// P001003 - Find the Minimum Element in a Heap
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const arr = [];
    for (let i = 0; i < n; i++) {
        arr.push(parseInt(input[1 + i], 10));
    }
    const leafStart = Math.floor(n / 2);
    let minVal = arr[leafStart];
    for (let i = leafStart + 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    console.log(minVal);
}

main();
