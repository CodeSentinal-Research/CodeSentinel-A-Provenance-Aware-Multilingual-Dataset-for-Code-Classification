// P001594 - Prefix Sum Array
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let cur = 0n;
    const res = [];
    for (let i = 0; i < n; i++) {
        cur += BigInt(input[1 + i]);
        res.push(cur.toString());
    }
    console.log(res.join(" "));
}

main();
