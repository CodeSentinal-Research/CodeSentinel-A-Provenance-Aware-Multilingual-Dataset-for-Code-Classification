// P001429 - Tuple With Same Product
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n1 = parseInt(input[0], 10);
    const n2 = parseInt(input[1], 10);
    const n3 = parseInt(input[2], 10);
    let ptr = 3;
    const s1 = new Set(), s2 = new Set(), s3 = new Set();
    for (let i = 0; i < n1; i++) s1.add(parseInt(input[ptr++], 10));
    for (let i = 0; i < n2; i++) s2.add(parseInt(input[ptr++], 10));
    for (let i = 0; i < n3; i++) s3.add(parseInt(input[ptr++], 10));
    const all = new Set([...s1, ...s2, ...s3]);
    const res = [];
    for (const x of all) {
        let count = 0;
        if (s1.has(x)) count++;
        if (s2.has(x)) count++;
        if (s3.has(x)) count++;
        if (count >= 2) res.push(x);
    }
    res.sort((a, b) => a - b);
    console.log(res.join(" "));
}

main();
