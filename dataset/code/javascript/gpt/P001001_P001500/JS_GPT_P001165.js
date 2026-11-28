// P001165 - Maximum Product Subarray
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    let maxProd = nums[0], minProd = nums[0], result = nums[0];
    for (let i = 1; i < n; i++) {
        const x = nums[i];
        if (x < 0) {
            const temp = maxProd;
            maxProd = minProd;
            minProd = temp;
        }
        maxProd = Math.max(x, maxProd * x);
        minProd = Math.min(x, minProd * x);
        result = Math.max(result, maxProd);
    }
    console.log(result);
}

main();
