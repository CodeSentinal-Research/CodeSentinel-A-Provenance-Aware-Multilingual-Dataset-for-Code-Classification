// P001600 - Range Average Query
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const prefix = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[ptr++], 10);
        prefix[i + 1] = prefix[i] + x;
    }
    const q = parseInt(input[ptr++], 10);
    for (let qi = 0; qi < q; qi++) {
        const l = parseInt(input[ptr++], 10);
        const r = parseInt(input[ptr++], 10);
        const sum = prefix[r + 1] - prefix[l];
        const len = r - l + 1;
        console.log(sum / len);
    }
}

main();
