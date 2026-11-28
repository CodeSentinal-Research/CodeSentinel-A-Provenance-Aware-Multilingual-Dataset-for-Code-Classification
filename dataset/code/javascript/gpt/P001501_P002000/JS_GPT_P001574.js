// P001574 - Maximum Element in the First Window
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const s = input[0];
    const t = input[1];
    const maxCost = parseInt(input[2], 10);
    let l = 0, cost = 0, maxLen = 0;
    for (let r = 0; r < s.length; r++) {
        cost += Math.abs(s.charCodeAt(r) - t.charCodeAt(r));
        while (cost > maxCost) {
            cost -= Math.abs(s.charCodeAt(l) - t.charCodeAt(l));
            l++;
        }
        maxLen = Math.max(maxLen, r - l + 1);
    }
    console.log(maxLen);
}

main();
