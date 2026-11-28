// P001415 - K-Diff Pairs in an Array
const fs = require("fs");

function getMask(word) {
    let mask = 0;
    for (let i = 0; i < word.length; i++) {
        mask |= (1 << (word.charCodeAt(i) - 97));
    }
    return mask;
}

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const map = new Map();
    let pairs = 0;
    for (let i = 0; i < n; i++) {
        const word = input[1 + i];
        const mask = getMask(word);
        const count = map.get(mask) || 0;
        pairs += count;
        map.set(mask, count + 1);
    }
    console.log(pairs);
}

main();
