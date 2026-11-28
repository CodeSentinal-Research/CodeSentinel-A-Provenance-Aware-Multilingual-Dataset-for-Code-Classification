// P001284 - Minimum Domino Rotations
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const tops = [];
    for (let i = 0; i < n; i++) tops.push(parseInt(input[ptr++], 10));
    const bottoms = [];
    for (let i = 0; i < n; i++) bottoms.push(parseInt(input[ptr++], 10));
    function check(target) {
        let rotA = 0, rotB = 0;
        for (let i = 0; i < n; i++) {
            if (tops[i] !== target && bottoms[i] !== target) return Infinity;
            if (tops[i] !== target) rotA++;
            if (bottoms[i] !== target) rotB++;
        }
        return Math.min(rotA, rotB);
    }
    const ans = Math.min(check(tops[0]), check(bottoms[0]));
    console.log(ans === Infinity ? -1 : ans);
}

main();
