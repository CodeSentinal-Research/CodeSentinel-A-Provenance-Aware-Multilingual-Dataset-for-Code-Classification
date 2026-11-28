// P001018 - Reorganize String
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    const count = new Map();
    for (const c of s) count.set(c, (count.get(c) || 0) + 1);
    const maxHeap = Array.from(count.entries()).sort((a, b) => b[1] - a[1]);
    if (maxHeap[0][1] > Math.ceil(s.length / 2)) {
        console.log("");
        return;
    }
    const res = new Array(s.length);
    let idx = 0;
    for (const [char, freq] of maxHeap) {
        for (let i = 0; i < freq; i++) {
            if (idx >= s.length) idx = 1;
            res[idx] = char;
            idx += 2;
        }
    }
    console.log(res.join(""));
}

main();
