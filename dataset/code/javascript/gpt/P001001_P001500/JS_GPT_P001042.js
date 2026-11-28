// P001042 - Find All Leaf Nodes of a Heap
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(input[1 + i]);
    const leafStart = Math.floor(n / 2);
    const leaves = arr.slice(leafStart);
    console.log(leaves.join(" "));
}

main();
