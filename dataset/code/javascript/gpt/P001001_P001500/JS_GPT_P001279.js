// P001279 - Smallest String with Given Numeric Value
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    let k = parseInt(input[1], 10);
    const res = new Array(n).fill("a");
    k -= n;
    for (let i = n - 1; i >= 0 && k > 0; i--) {
        const add = Math.min(25, k);
        res[i] = String.fromCharCode(97 + add);
        k -= add;
    }
    console.log(res.join(""));
}

main();
