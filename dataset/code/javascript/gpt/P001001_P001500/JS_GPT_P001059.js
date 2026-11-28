// P001059 - Minimize Deviation in an Array
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    let minVal = Infinity;
    for (let i = 0; i < n; i++) {
        let val = parseInt(input[1 + i], 10);
        if (val % 2 === 1) val *= 2;
        nums.push(val);
        if (val < minVal) minVal = val;
    }
    nums.sort((a, b) => b - a);
    let minDev = nums[0] - minVal;
    while (nums[0] % 2 === 0) {
        let maxVal = nums.shift();
        maxVal = Math.floor(maxVal / 2);
        if (maxVal < minVal) minVal = maxVal;
        let low = 0, high = nums.length;
        while (low < high) {
            const mid = (low + high) >> 1;
            if (nums[mid] > maxVal) low = mid + 1;
            else high = mid;
        }
        nums.splice(low, 0, maxVal);
        minDev = Math.min(minDev, nums[0] - minVal);
    }
    console.log(minDev);
}

main();
