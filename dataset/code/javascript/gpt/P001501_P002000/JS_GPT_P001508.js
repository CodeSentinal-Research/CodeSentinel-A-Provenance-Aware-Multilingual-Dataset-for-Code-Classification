// P001508 - Fruit Into Baskets
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const fruits = [];
    for (let i = 0; i < n; i++) fruits.push(parseInt(input[1 + i], 10));
    const count = new Map();
    let l = 0, maxFruits = 0;
    for (let r = 0; r < n; r++) {
        const f = fruits[r];
        count.set(f, (count.get(f) || 0) + 1);
        while (count.size > 2) {
            const leftF = fruits[l];
            const c = count.get(leftF) - 1;
            if (c === 0) count.delete(leftF);
            else count.set(leftF, c);
            l++;
        }
        maxFruits = Math.max(maxFruits, r - l + 1);
    }
    console.log(maxFruits);
}

main();
