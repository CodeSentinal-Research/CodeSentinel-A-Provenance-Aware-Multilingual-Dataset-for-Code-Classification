// P001169 - Dungeon Game
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const r = parseInt(input[0], 10);
    const c = parseInt(input[1], 10);
    let ptr = 2;
    const dungeon = [];
    for (let i = 0; i < r; i++) {
        const row = [];
        for (let j = 0; j < c; j++) row.push(parseInt(input[ptr++], 10));
        dungeon.push(row);
    }
    const dp = Array.from({ length: r + 1 }, () => new Array(c + 1).fill(Infinity));
    dp[r][c - 1] = 1;
    dp[r - 1][c] = 1;
    for (let i = r - 1; i >= 0; i--) {
        for (let j = c - 1; j >= 0; j--) {
            const minHealth = Math.min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
            dp[i][j] = Math.max(1, minHealth);
        }
    }
    console.log(dp[0][0]);
}

main();
