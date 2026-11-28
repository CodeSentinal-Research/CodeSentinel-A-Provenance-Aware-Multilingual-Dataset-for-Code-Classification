const fs = require("fs");

const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/);
if (!tokens.length || tokens[0] === "") process.exit(0);

const n = Number(tokens[0]);
const a = new Array(n);
for (let i = 0; i < n; i++) a[i] = Number(tokens[i + 1]);

if (n <= 2) {
    console.log("YES");
    process.exit(0);
}

// In a BST preorder, each internal node with exactly one child
// has all remaining descendants on only one side of that node.
let lower = -Infinity;

for (let i = 0; i < n - 2; i++) {
    if (a[i] < lower) {
        console.log("NO");
        process.exit(0);
    }

    const next = a[i + 1];
    const later = a[i + 2];

    const nextIsLeft = next < a[i];
    const laterIsLeft = later < a[i];

    if (nextIsLeft !== laterIsLeft) {
        console.log("NO");
        process.exit(0);
    }

    if (nextIsLeft) {
        // Later values may eventually cross the current ancestor bound.
        continue;
    }

    if (next > a[i]) {
        lower = Math.max(lower, a[i]);
    }
}

console.log("YES");
