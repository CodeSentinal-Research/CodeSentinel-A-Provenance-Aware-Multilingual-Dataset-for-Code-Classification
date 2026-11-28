// P001572 - Count Windows With Even Sum
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const minK = parseInt(input[1], 10);
    const maxK = parseInt(input[2], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[3 + i], 10));
    let badIdx = -1, minIdx = -1, maxIdx = -1, ans = 0;
    for (let i = 0; i < n; i++) {
        if (nums[i] < minK || nums[i] > maxK) badIdx = i;
        if (nums[i] === minK) minIdx = i;
        if (nums[i] === maxK) maxIdx = i;
        const validStart = Math.min(minIdx, maxIdx);
        if (validStart > badIdx) {
            ans += validStart - badIdx;
        }
    }
    console.log(ans);
}

main();
