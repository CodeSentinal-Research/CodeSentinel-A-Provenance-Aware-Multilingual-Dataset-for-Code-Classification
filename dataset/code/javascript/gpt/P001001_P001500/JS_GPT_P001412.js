// P001412 - Count Pairs With Given Difference
const fs = require("fs");

function gcd(a, b) {
    while (b) {
        let t = b;
        b = a % b;
        a = t;
    }
    return a;
}

function lcm(a, b) {
    return (a * b) / gcd(a, b);
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
        let curLcm = nums[i];
        for (let j = i; j < n; j++) {
            curLcm = lcm(curLcm, nums[j]);
            if (curLcm === k) count++;
            if (curLcm > k || k % curLcm !== 0) break;
        }
    }
    console.log(count);
}

main();
