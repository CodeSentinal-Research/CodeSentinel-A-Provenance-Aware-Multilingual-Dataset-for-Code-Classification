// P001005 - Count Leaf Nodes in a Heap
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    if (n <= 0) {
        console.log(0);
        return;
    }
    console.log(Math.ceil(n / 2));
}

main();
