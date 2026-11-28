// P001422 - Keyboard Row
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    const totalDistinct = new Set(nums).size;
    let count = 0;
    for (let i = 0; i < n; i++) {
        const cur = new Set();
        for (let j = i; j < n; j++) {
            cur.add(nums[j]);
            if (cur.size === totalDistinct) count++;
        }
    }
    console.log(count);
}

main();
