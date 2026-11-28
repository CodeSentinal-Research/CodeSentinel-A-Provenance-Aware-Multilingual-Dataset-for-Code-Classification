// P001049 - Replace Multiple Keys in a Heap
const fs = require("fs");

function maxHeapify(arr, n, i) {
    let largest = i;
    const l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest !== i) {
        const temp = arr[i]; arr[i] = arr[largest]; arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const q = parseInt(input[1], 10);
    let ptr = 2;
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[ptr++], 10));
    for (let k = 0; k < q; k++) {
        const idx = parseInt(input[ptr++], 10);
        const val = parseInt(input[ptr++], 10);
        arr[idx] = val;
    }
    for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
    console.log(arr.join(" "));
}

main();
