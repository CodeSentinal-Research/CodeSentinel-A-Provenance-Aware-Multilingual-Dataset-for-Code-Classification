// P001226 - Friends Pairing Problem
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const r = parseInt(input[0], 10);
    const c = parseInt(input[1], 10);
    let ptr = 2;
    const grid = [];
    for (let i = 0; i < r; i++) {
        const row = [];
        for (let j = 0; j < c; j++) row.push(BigInt(input[ptr++]));
        grid.push(row);
    }
    const maxDP = Array.from({ length: r }, () => new Array(c).fill(0n));
    const minDP = Array.from({ length: r }, () => new Array(c).fill(0n));
    maxDP[0][0] = minDP[0][0] = grid[0][0];
    for (let i = 1; i < r; i++) {
        maxDP[i][0] = minDP[i][0] = maxDP[i - 1][0] * grid[i][0];
    }
    for (let j = 1; j < c; j++) {
        maxDP[0][j] = minDP[0][j] = maxDP[0][j - 1] * grid[0][j];
    }
    for (let i = 1; i < r; i++) {
        for (let j = 1; j < c; j++) {
            const v = grid[i][j];
            const p1 = maxDP[i - 1][j] * v;
            const p2 = minDP[i - 1][j] * v;
            const p3 = maxDP[i][j - 1] * v;
            const p4 = minDP[i][j - 1] * v;
            const all = [p1, p2, p3, p4];
            let mx = all[0], mn = all[0];
            for (const x of all) {
                if (x > mx) mx = x;
                if (x < mn) mn = x;
            }
            maxDP[i][j] = mx;
            minDP[i][j] = mn;
        }
    }
    const ans = maxDP[r - 1][c - 1];
    if (ans < 0n) {
        console.log("-1");
    } else {
        const MOD = 1000000007n;
        console.log((ans % MOD).toString());
    }
}

main();
