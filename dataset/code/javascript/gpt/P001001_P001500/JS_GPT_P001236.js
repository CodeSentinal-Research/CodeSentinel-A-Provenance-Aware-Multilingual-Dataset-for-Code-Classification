// P001236 - Minimum Number of Arrows to Burst Balloons
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const ratings = [];
    for (let i = 0; i < n; i++) ratings.push(parseInt(input[1 + i], 10));
    const candies = new Array(n).fill(1);
    for (let i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
    }
    for (let i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) candies[i] = Math.max(candies[i], candies[i + 1] + 1);
    }
    let total = 0;
    for (const c of candies) total += c;
    console.log(total);
}

main();
