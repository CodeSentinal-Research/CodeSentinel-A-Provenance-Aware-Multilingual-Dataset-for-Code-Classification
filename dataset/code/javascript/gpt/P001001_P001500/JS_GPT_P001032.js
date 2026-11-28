// P001032 - Replace Root in a Min Heap
const fs = require("fs");

function minHeapify(arr, n, i) {
    let smallest = i;
    const l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest !== i) {
        const temp = arr[i]; arr[i] = arr[smallest]; arr[smallest] = temp;
        minHeapify(arr, n, smallest);
    }
}

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const x = parseInt(input[1], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[2 + i], 10));
    arr[0] = x;
    minHeapify(arr, n, 0);
    console.log(arr.join(" "));
}

main();
