// P001280 - Patch Array
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const maxVal = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    let miss = 1, added = 0, i = 0;
    while (miss <= maxVal) {
        if (i < n && nums[i] <= miss) {
            miss += nums[i];
            i++;
        } else {
            miss += miss;
            added++;
        }
    }
    console.log(added);
}

main();
