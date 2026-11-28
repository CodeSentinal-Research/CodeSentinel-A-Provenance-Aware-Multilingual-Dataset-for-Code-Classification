// P001343 - Generate Gray Code
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    const res = [];
    for (let i = 0; i < (1 << n); i++) {
        res.push(i ^ (i >> 1));
    }
    console.log(res.join(" "));
}

main();
