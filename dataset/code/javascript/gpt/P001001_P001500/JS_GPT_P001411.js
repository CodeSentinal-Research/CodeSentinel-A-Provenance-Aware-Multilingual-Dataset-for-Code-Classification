// P001411 - Find Players With Zero or One Loss
const fs = require("fs");

function gcd(a, b) {
    while (b) {
        let t = b;
        b = a % b;
        a = t;
    }
    return a;
}

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    let count = 0;
    for (let i = 0; i < n; i++) {
        let curGcd = 0;
        for (let j = i; j < n; j++) {
            curGcd = gcd(curGcd, nums[j]);
            if (curGcd === k) count++;
            if (curGcd < k) break;
        }
    }
    console.log(count);
}

main();
