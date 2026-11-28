// P001181 - Jump Game
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    let maxReach = 0;
    for (let i = 0; i < n; i++) {
        if (i > maxReach) {
            console.log("NO");
            return;
        }
        maxReach = Math.max(maxReach, i + nums[i]);
    }
    console.log("YES");
}

main();
