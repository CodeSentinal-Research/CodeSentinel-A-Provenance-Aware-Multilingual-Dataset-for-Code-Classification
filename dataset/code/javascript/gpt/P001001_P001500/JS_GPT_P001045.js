// P001045 - Check Whether Two Heaps are Identical
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    if (n !== m) {
        console.log("NO");
        return;
    }
    let ptr = 2;
    const arr1 = [];
    for (let i = 0; i < n; i++) arr1.push(input[ptr++]);
    const arr2 = [];
    for (let i = 0; i < m; i++) arr2.push(input[ptr++]);
    for (let i = 0; i < n; i++) {
        if (arr1[i] !== arr2[i]) {
            console.log("NO");
            return;
        }
    }
    console.log("YES");
}

main();
