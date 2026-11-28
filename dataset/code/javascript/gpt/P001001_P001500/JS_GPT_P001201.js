// P001201 - Minimum Falling Path Sum II
const fs = require("fs");

function main() {
    const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
    if (!lines || lines.length < 2) return;
    const s = lines[0].trim();
    const t = lines[1].trim();
    let ans = 0;
    for (let i = 0; i < s.length; i++) {
        for (let j = 0; j < t.length; j++) {
            let diff = 0;
            for (let k = 0; i + k < s.length && j + k < t.length; k++) {
                if (s[i + k] !== t[j + k]) diff++;
                if (diff === 1) ans++;
                if (diff > 1) break;
            }
        }
    }
    console.log(ans);
}

main();
