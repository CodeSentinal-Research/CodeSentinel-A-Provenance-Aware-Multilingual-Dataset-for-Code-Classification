// P001287 - Divide Chocolate
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const sweetness = [];
    let sum = 0;
    for (let i = 0; i < n; i++) {
        const val = parseInt(input[2 + i], 10);
        sweetness.push(val);
        sum += val;
    }
    let low = 1, high = sum, ans = 1;
    while (low <= high) {
        const mid = (low + high) >> 1;
        let count = 0, curSum = 0;
        for (const s of sweetness) {
            curSum += s;
            if (curSum >= mid) {
                count++;
                curSum = 0;
            }
        }
        if (count >= k + 1) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    console.log(ans);
}

main();
