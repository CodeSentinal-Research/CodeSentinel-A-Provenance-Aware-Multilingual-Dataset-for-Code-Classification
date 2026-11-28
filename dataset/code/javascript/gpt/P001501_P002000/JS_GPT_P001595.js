// P001595 - Sum Between Two Positions
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(BigInt(input[ptr++]));
    const l = parseInt(input[ptr++], 10);
    const r = parseInt(input[ptr++], 10);
    let sum = 0n;
    for (let i = l; i <= r; i++) sum += nums[i];
    console.log(sum.toString());
}

main();
