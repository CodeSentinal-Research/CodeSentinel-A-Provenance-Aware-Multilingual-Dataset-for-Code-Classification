// P001298 - Maximum Number of Weeks for Projects
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const milestones = [];
    let sum = 0n, maxVal = 0n;
    for (let i = 0; i < n; i++) {
        const val = BigInt(input[1 + i]);
        milestones.push(val);
        sum += val;
        if (val > maxVal) maxVal = val;
    }
    const rest = sum - maxVal;
    if (maxVal > rest + 1n) {
        console.log((2n * rest + 1n).toString());
    } else {
        console.log(sum.toString());
    }
}

main();
