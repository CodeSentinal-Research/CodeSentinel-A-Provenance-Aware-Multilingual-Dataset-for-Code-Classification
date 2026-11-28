// P001009 - Delete Root from a Max Heap
const fs = require("fs");

function maxHeapify(arr, n, i) {
    let largest = i;
    const l = 2 * i + 1;
    const r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest !== i) {
        const temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const arr = [];
    for (let i = 0; i < n; i++) {
        arr.push(parseInt(input[1 + i], 10));
    }
    if (n <= 1) {
        console.log("");
        return;
    }
    arr[0] = arr.pop();
    maxHeapify(arr, arr.length, 0);
    console.log(arr.join(" "));
}

main();
