// P001027 - Print Heap Level Order
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(input[1 + i]);
    console.log(arr.join(" "));
}

main();
