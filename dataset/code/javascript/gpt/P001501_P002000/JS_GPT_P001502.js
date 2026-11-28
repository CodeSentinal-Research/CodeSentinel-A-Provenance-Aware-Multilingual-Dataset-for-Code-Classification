// P001502 - Minimum Swaps to Group All Ones Together
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const data = [];
    for (let i = 0; i < n; i++) data.push(parseInt(input[1 + i], 10));
    let totalOnes = 0;
    for (const x of data) if (x === 1) totalOnes++;
    if (totalOnes <= 1) {
        console.log(0);
        return;
    }
    let curOnes = 0;
    for (let i = 0; i < totalOnes; i++) if (data[i] === 1) curOnes++;
    let maxOnes = curOnes;
    for (let i = totalOnes; i < n; i++) {
        if (data[i] === 1) curOnes++;
        if (data[i - totalOnes] === 1) curOnes--;
        maxOnes = Math.max(maxOnes, curOnes);
    }
    console.log(totalOnes - maxOnes);
}

main();
