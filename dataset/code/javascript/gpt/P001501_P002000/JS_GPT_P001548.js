// P001548 - Window With Highest Product (Positive Numbers)
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(BigInt(input[2 + i]));
    let curProd = 1n;
    for (let i = 0; i < k; i++) curProd *= nums[i];
    let maxProd = curProd;
    for (let i = k; i < n; i++) {
        curProd = (curProd / nums[i - k]) * nums[i];
        if (curProd > maxProd) maxProd = curProd;
    }
    console.log(maxProd.toString());
}

main();
