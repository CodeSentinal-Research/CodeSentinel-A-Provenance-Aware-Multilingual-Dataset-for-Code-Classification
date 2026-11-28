// P001478 - Interval List Intersections
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const h = [];
    for (let i = 0; i < n; i++) h.push(parseInt(input[1 + i], 10));
    let l = 0, r = n - 1;
    let leftMax = 0, rightMax = 0;
    let water = 0;
    while (l < r) {
        if (h[l] < h[r]) {
            if (h[l] >= leftMax) leftMax = h[l];
            else water += leftMax - h[l];
            l++;
        } else {
            if (h[r] >= rightMax) rightMax = h[r];
            else water += rightMax - h[r];
            r--;
        }
    }
    console.log(water);
}

main();
