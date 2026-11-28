// P001208 - Stone Game II
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const a = [];
    for (let i = 0; i < n; i++) a.push(parseInt(input[ptr++], 10));
    const b = [];
    for (let i = 0; i < n; i++) b.push(parseInt(input[ptr++], 10));
    let keep = 0, swap = 1;
    for (let i = 1; i < n; i++) {
        let nextKeep = Infinity, nextSwap = Infinity;
        if (a[i] > a[i - 1] && b[i] > b[i - 1]) {
            nextKeep = keep;
            nextSwap = swap + 1;
        }
        if (a[i] > b[i - 1] && b[i] > a[i - 1]) {
            nextKeep = Math.min(nextKeep, swap);
            nextSwap = Math.min(nextSwap, keep + 1);
        }
        keep = nextKeep;
        swap = nextSwap;
    }
    console.log(Math.min(keep, swap));
}

main();
