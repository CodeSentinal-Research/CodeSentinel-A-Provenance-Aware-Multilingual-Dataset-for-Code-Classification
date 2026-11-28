// P001012 - Merge Two Min Heaps
const fs = require("fs");

function minHeapify(arr, n, i) {
    let smallest = i;
    const l = 2 * i + 1;
    const r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest !== i) {
        const temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        minHeapify(arr, n, smallest);
    }
}

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[ptr++], 10));
    for (let i = 0; i < m; i++) arr.push(parseInt(input[ptr++], 10));
    const total = arr.length;
    for (let i = Math.floor(total / 2) - 1; i >= 0; i--) {
        minHeapify(arr, total, i);
    }
    console.log(arr.join(" "));
}

main();
