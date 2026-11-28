// P001257 - Partition Labels
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    const last = new Map();
    for (let i = 0; i < s.length; i++) last.set(s[i], i);
    let start = 0, end = 0;
    const res = [];
    for (let i = 0; i < s.length; i++) {
        end = Math.max(end, last.get(s[i]));
        if (i === end) {
            res.push(end - start + 1);
            start = i + 1;
        }
    }
    console.log(res.join(" "));
}

main();
