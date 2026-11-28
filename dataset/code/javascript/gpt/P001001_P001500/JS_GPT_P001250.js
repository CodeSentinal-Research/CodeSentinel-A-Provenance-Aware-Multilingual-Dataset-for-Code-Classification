// P001250 - Split Array into Consecutive Subsequences
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    let first = Infinity, second = Infinity;
    for (const x of nums) {
        if (x <= first) first = x;
        else if (x <= second) second = x;
        else {
            console.log("YES");
            return;
        }
    }
    console.log("NO");
}

main();
