// P001452 - Count Distinct Elements After Updates
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const q = parseInt(input[1], 10);
    let ptr = 2;
    const arr = [];
    const freq = new Map();
    for (let i = 0; i < n; i++) {
        const val = parseInt(input[ptr++], 10);
        arr.push(val);
        freq.set(val, (freq.get(val) || 0) + 1);
    }
    for (let qi = 0; qi < q; qi++) {
        const idx = parseInt(input[ptr++], 10);
        const newVal = parseInt(input[ptr++], 10);
        const oldVal = arr[idx];
        if (oldVal !== newVal) {
            const oldCount = freq.get(oldVal);
            if (oldCount === 1) freq.delete(oldVal);
            else freq.set(oldVal, oldCount - 1);
            arr[idx] = newVal;
            freq.set(newVal, (freq.get(newVal) || 0) + 1);
        }
        console.log(freq.size);
    }
}

main();
