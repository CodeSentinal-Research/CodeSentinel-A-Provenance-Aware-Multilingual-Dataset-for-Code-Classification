// P001597 - Count Elements Equal to X in a Range
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[ptr++], 10));
    const q = parseInt(input[ptr++], 10);
    for (let qi = 0; qi < q; qi++) {
        const l = parseInt(input[ptr++], 10);
        const r = parseInt(input[ptr++], 10);
        const x = parseInt(input[ptr++], 10);
        let count = 0;
        for (let i = l; i <= r; i++) {
            if (nums[i] === x) count++;
        }
        console.log(count);
    }
}

main();
