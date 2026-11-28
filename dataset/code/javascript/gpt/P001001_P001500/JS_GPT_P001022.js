// P001022 - Decrease Key in a Min Heap
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const idx = parseInt(input[1], 10);
    const newVal = parseInt(input[2], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[3 + i], 10));
    arr[idx] = newVal;
    let curr = idx;
    while (curr > 0) {
        const p = Math.floor((curr - 1) / 2);
        if (arr[p] > arr[curr]) {
            const temp = arr[curr]; arr[curr] = arr[p]; arr[p] = temp;
            curr = p;
        } else {
            break;
        }
    }
    console.log(arr.join(" "));
}

main();
