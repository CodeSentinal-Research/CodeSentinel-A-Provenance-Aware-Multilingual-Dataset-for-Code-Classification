// P001518 - Successful Pairs of Spells and Potions
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    const success = BigInt(input[2]);
    let ptr = 3;
    const spells = [];
    for (let i = 0; i < n; i++) spells.push(BigInt(input[ptr++]));
    const potions = [];
    for (let i = 0; i < m; i++) potions.push(BigInt(input[ptr++]));
    potions.sort((a, b) => (a < b ? -1 : a > b ? 1 : 0));
    const res = [];
    for (let i = 0; i < n; i++) {
        const spell = spells[i];
        let low = 0, high = m - 1, firstIdx = m;
        while (low <= high) {
            const mid = (low + high) >> 1;
            if (spell * potions[mid] >= success) {
                firstIdx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        res.push(m - firstIdx);
    }
    console.log(res.join(" "));
}

main();
