// P001367 - Matchsticks Game Winner
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    console.log(n % 4 !== 0 ? "FIRST" : "SECOND");
}

main();
