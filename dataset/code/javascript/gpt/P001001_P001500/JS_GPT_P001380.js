// P001380 - Frequency Sort
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const count = new Map();
    for (let i = 0; i < n; i++) {
        const val = parseInt(input[1 + i], 10);
        count.set(val, (count.get(val) || 0) + 1);
    }
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[1 + i], 10));
    arr.sort((a, b) => {
        const fa = count.get(a), fb = count.get(b);
        if (fa !== fb) return fb - fa;
        return a - b;
    });
    console.log(arr.join(" "));
}

main();
