// P001218 - Word Break
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const shelfWidth = parseInt(input[1], 10);
    let ptr = 2;
    const books = [];
    for (let i = 0; i < n; i++) {
        const w = parseInt(input[ptr++], 10);
        const h = parseInt(input[ptr++], 10);
        books.push([w, h]);
    }
    const dp = new Array(n + 1).fill(Infinity);
    dp[0] = 0;
    for (let i = 1; i <= n; i++) {
        let width = 0, height = 0;
        for (let j = i; j >= 1; j--) {
            width += books[j - 1][0];
            if (width > shelfWidth) break;
            height = Math.max(height, books[j - 1][1]);
            dp[i] = Math.min(dp[i], dp[j - 1] + height);
        }
    }
    console.log(dp[n]);
}

main();
