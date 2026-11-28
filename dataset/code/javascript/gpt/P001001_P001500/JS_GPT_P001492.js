// P001492 - Find K Closest Elements
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const x = parseInt(input[2], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[3 + i], 10));
    let l = 0, r = n - k;
    while (l < r) {
        const mid = (l + r) >> 1;
        if (x - arr[mid] > arr[mid + k] - x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    const res = arr.slice(l, l + k);
    console.log(res.join(" "));
}

main();
