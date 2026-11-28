// P001051 - Heap Validation After Updates
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const idx = parseInt(input[1], 10);
    const val = parseInt(input[2], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[3 + i], 10));
    arr[idx] = val;
    for (let i = 0; i <= Math.floor((n - 2) / 2); i++) {
        const left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && arr[i] < arr[left]) {
            console.log("INVALID");
            return;
        }
        if (right < n && arr[i] < arr[right]) {
            console.log("INVALID");
            return;
        }
    }
    console.log("VALID");
}

main();
