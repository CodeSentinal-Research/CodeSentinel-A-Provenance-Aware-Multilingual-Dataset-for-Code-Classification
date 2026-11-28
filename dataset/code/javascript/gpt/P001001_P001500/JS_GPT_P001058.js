// P001058 - Frequency Stack
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const q = parseInt(input[0], 10);
    let ptr = 1;
    const freq = new Map();
    const group = new Map();
    let maxFreq = 0;
    const out = [];
    for (let i = 0; i < q; i++) {
        const op = input[ptr++];
        if (op === "push") {
            const val = parseInt(input[ptr++], 10);
            const f = (freq.get(val) || 0) + 1;
            freq.set(val, f);
            if (f > maxFreq) maxFreq = f;
            if (!group.has(f)) group.set(f, []);
            group.get(f).push(val);
        } else if (op === "pop") {
            const val = group.get(maxFreq).pop();
            freq.set(val, freq.get(val) - 1);
            if (group.get(maxFreq).length === 0) maxFreq--;
            out.push(val);
        }
    }
    for (const val of out) console.log(val);
}

main();
