// P001211 - Partition to K Equal Sum Subsets
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const k = parseInt(input[0], 10);
    const digits = [];
    for (let i = 0; i < k; i++) digits.push(input[1 + i]);
    const nStr = input[1 + k];
    const len = nStr.length;
    let total = 0;
    for (let i = 1; i < len; i++) {
        total += Math.pow(k, i);
    }
    for (let i = 0; i < len; i++) {
        let hasSame = false;
        for (const d of digits) {
            if (d < nStr[i]) {
                total += Math.pow(k, len - i - 1);
            } else if (d === nStr[i]) {
                hasSame = true;
            }
        }
        if (!hasSame) return console.log(total);
    }
    console.log(total + 1);
}

main();
