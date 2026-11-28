// P001408 - Recover the Original Array
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n2 = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n2; i++) nums.push(parseInt(input[1 + i], 10));
    nums.sort((a, b) => a - b);
    const n = n2 / 2;
    for (let i = 1; i < n2; i++) {
        const diff = nums[i] - nums[0];
        if (diff === 0 || diff % 2 !== 0) continue;
        const k = diff / 2;
        const count = new Map();
        for (const x of nums) count.set(x, (count.get(x) || 0) + 1);
        const res = [];
        let possible = true;
        for (const x of nums) {
            if ((count.get(x) || 0) === 0) continue;
            count.set(x, count.get(x) - 1);
            const pair = x + 2 * k;
            if ((count.get(pair) || 0) === 0) {
                possible = false;
                break;
            }
            count.set(pair, count.get(pair) - 1);
            res.push(x + k);
        }
        if (possible && res.length === n) {
            console.log(res.join(" "));
            return;
        }
    }
    console.log("-1");
}

main();
