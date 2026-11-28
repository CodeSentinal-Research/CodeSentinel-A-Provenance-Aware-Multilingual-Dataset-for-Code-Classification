// P001222 - Catalan Number
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    const MOD = 1000000007n;
    let ans = 1n;
    for (let i = 1n; i <= BigInt(n); i++) {
        ans = (ans * i * (2n * i - 1n)) % MOD;
    }
    console.log(ans.toString());
}

main();
