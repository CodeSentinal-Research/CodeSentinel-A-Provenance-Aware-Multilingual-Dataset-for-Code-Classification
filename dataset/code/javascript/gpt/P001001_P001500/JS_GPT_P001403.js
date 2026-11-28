// P001403 - Check Arithmetic Subarrays
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const q = parseInt(input[1], 10);
    let ptr = 2;
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[ptr++], 10));
    for (let qi = 0; qi < q; qi++) {
        const l = parseInt(input[ptr++], 10);
        const r = parseInt(input[ptr++], 10);
        const sub = nums.slice(l, r + 1).sort((a, b) => a - b);
        if (sub.length < 2) {
            console.log("YES");
            continue;
        }
        const diff = sub[1] - sub[0];
        let ok = true;
        for (let j = 2; j < sub.length; j++) {
            if (sub[j] - sub[j - 1] !== diff) {
                ok = false;
                break;
            }
        }
        console.log(ok ? "YES" : "NO");
    }
}

main();
