// P001361 - Stickers to Spell Word
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const stickers = [];
    for (let i = 0; i < n; i++) stickers.push(input[ptr++]);
    const target = input[ptr++];
    const m = target.length;
    const dp = new Array(1 << m).fill(Infinity);
    dp[0] = 0;
    for (let mask = 0; mask < (1 << m); mask++) {
        if (dp[mask] === Infinity) continue;
        for (const sticker of stickers) {
            let nextMask = mask;
            for (const c of sticker) {
                for (let i = 0; i < m; i++) {
                    if (target[i] === c && !((nextMask >> i) & 1)) {
                        nextMask |= (1 << i);
                        break;
                    }
                }
            }
            dp[nextMask] = Math.min(dp[nextMask], dp[mask] + 1);
        }
    }
    const ans = dp[(1 << m) - 1];
    console.log(ans === Infinity ? -1 : ans);
}

main();
