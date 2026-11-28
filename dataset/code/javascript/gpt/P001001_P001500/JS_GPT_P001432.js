// P001432 - Number of Equivalent Domino Pairs
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const map = new Map();
    let pairs = 0;
    for (let i = 0; i < n; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        const key = u <= v ? `${u},${v}` : `${v},${u}`;
        const count = map.get(key) || 0;
        pairs += count;
        map.set(key, count + 1);
    }
    console.log(pairs);
}

main();
