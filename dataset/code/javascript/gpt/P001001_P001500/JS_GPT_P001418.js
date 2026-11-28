// P001418 - Count Number of Consistent Strings
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    nums.sort((a, b) => a - b);
    let j = 0;
    for (let i = 0; i < n; i++) {
        if (nums[i] > nums[j]) {
            j++;
        }
    }
    console.log(j);
}

main();
