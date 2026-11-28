// P001566 - Sliding Window Minimum
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const cards = [];
    for (let i = 0; i < n; i++) cards.push(parseInt(input[1 + i], 10));
    const lastPos = new Map();
    let minCards = Infinity;
    for (let i = 0; i < n; i++) {
        const c = cards[i];
        if (lastPos.has(c)) {
            minCards = Math.min(minCards, i - lastPos.get(c) + 1);
        }
        lastPos.set(c, i);
    }
    console.log(minCards === Infinity ? -1 : minCards);
}

main();
