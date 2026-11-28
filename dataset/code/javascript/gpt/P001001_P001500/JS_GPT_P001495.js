// P001495 - Append Characters to String to Make Subsequence
const fs = require("fs");

function main() {
    const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
    if (!lines || lines.length < 2) return;
    const s = lines[0].trim();
    const t = lines[1].trim();
    let si = 0, ti = 0;
    while (si < s.length && ti < t.length) {
        if (s[si] === t[ti]) {
            ti++;
        }
        si++;
    }
    console.log(t.length - ti);
}

main();
