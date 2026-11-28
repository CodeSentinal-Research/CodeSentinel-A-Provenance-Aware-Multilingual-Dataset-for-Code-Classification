// P001482 - Bag of Tokens
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    let power = parseInt(input[1], 10);
    const tokens = [];
    for (let i = 0; i < n; i++) tokens.push(parseInt(input[2 + i], 10));
    tokens.sort((a, b) => a - b);
    let l = 0, r = n - 1, score = 0, maxScore = 0;
    while (l <= r) {
        if (power >= tokens[l]) {
            power -= tokens[l];
            score++;
            l++;
            maxScore = Math.max(maxScore, score);
        } else if (score > 0 && l < r) {
            power += tokens[r];
            score--;
            r--;
        } else {
            break;
        }
    }
    console.log(maxScore);
}

main();
