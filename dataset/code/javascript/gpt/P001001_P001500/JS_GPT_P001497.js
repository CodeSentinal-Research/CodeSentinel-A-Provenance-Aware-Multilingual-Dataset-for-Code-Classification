// P001497 - Rearrange Array Elements by Sign
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    const res = new Array(n);
    let posIdx = 0, negIdx = 1;
    for (const x of nums) {
        if (x > 0) {
            res[posIdx] = x;
            posIdx += 2;
        } else {
            res[negIdx] = x;
            negIdx += 2;
        }
    }
    console.log(res.join(" "));
}

main();
