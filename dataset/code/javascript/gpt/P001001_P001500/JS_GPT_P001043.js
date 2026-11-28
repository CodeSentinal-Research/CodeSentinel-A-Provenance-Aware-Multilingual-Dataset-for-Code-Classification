// P001043 - Find the Last Internal Node
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    if (n <= 1) {
        console.log("-1");
    } else {
        console.log(Math.floor(n / 2) - 1);
    }
}

main();
