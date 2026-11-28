// P001426 - Find Lucky Integer in an Array
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    let total = 0;
    for (let i = 0; i < n; i++) {
        const set = new Set();
        for (let j = i; j < n; j++) {
            set.add(nums[j]);
            total += set.size * set.size;
        }
    }
    console.log(total);
}

main();
