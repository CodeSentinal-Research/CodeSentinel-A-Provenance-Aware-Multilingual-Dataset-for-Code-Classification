// P001435 - Count Common Words With One Occurrence
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const count1 = new Map(), count2 = new Map();
    for (let i = 0; i < n; i++) {
        const w = input[ptr++];
        count1.set(w, (count1.get(w) || 0) + 1);
    }
    for (let i = 0; i < m; i++) {
        const w = input[ptr++];
        count2.set(w, (count2.get(w) || 0) + 1);
    }
    let ans = 0;
    for (const [w, c] of count1.entries()) {
        if (c === 1 && count2.get(w) === 1) ans++;
    }
    console.log(ans);
}

main();
