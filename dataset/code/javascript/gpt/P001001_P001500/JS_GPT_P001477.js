// P001477 - Backspace String Compare
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const height = [];
    for (let i = 0; i < n; i++) height.push(parseInt(input[1 + i], 10));
    let l = 0, r = n - 1, maxArea = 0;
    while (l < r) {
        const area = Math.min(height[l], height[r]) * (r - l);
        maxArea = Math.max(maxArea, area);
        if (height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
    }
    console.log(maxArea);
}

main();
