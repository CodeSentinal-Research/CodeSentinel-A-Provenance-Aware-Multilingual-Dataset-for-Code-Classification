// P001297 - Maximize Sum After One Swap
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    let baseSum = 0;
    for (let i = 0; i < n; i++) baseSum += i * nums[i];
    let maxGain = 0;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const gain = (i * nums[j] + j * nums[i]) - (i * nums[i] + j * nums[j]);
            if (gain > maxGain) maxGain = gain;
        }
    }
    console.log(baseSum + maxGain);
}

main();
