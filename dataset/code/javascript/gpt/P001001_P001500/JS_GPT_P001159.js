// P001159 - Decode Ways
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s || s[0] === "0") { console.log(0); return; }
    const n = s.length;
    let prev2 = 1, prev1 = 1;
    for (let i = 1; i < n; i++) {
        let curr = 0;
        if (s[i] !== "0") curr += prev1;
        const twoDigit = parseInt(s.substring(i - 1, i + 1), 10);
        if (twoDigit >= 10 && twoDigit <= 26) curr += prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    console.log(prev1);
}

main();
