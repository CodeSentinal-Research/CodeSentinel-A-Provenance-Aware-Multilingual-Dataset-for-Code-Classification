// P001487 - Camelcase Matching
const fs = require("fs");

function isUpper(c) {
    return c >= 'A' && c <= 'Z';
}

function matches(q, p) {
    let pi = 0;
    for (let i = 0; i < q.length; i++) {
        if (pi < p.length && q[i] === p[pi]) {
            pi++;
        } else if (isUpper(q[i])) {
            return false;
        }
    }
    return pi === p.length;
}

function main() {
    const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
    if (!lines || lines.length < 3) return;
    const n = parseInt(lines[0].trim(), 10);
    const queries = [];
    for (let i = 1; i <= n; i++) queries.push(lines[i].trim());
    const pattern = lines[n + 1].trim();
    for (const q of queries) {
        console.log(matches(q, pattern) ? "YES" : "NO");
    }
}

main();
