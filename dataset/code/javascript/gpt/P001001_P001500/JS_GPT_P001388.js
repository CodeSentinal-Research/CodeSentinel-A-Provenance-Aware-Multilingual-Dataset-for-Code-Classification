// P001388 - Count Distinct Elements in Every Window
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[2 + i], 10));
    const freq = new Map();
    for (let i = 0; i < k; i++) freq.set(arr[i], (freq.get(arr[i]) || 0) + 1);
    const res = [freq.size];
    for (let i = k; i < n; i++) {
        const out = arr[i - k];
        const count = freq.get(out) - 1;
        if (count === 0) freq.delete(out);
        else freq.set(out, count);
        freq.set(arr[i], (freq.get(arr[i]) || 0) + 1);
        res.push(freq.size);
    }
    console.log(res.join(" "));
}

main();
