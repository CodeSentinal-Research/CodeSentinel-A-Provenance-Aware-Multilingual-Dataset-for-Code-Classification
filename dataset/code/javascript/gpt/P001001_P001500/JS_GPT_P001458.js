// P001458 - Count Distinct Palindromic Substrings
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    const n = s.length;
    const distinct = new Set();

    function expand(l, r) {
        while (l >= 0 && r < n && s[l] === s[r]) {
            distinct.add(s.substring(l, r + 1));
            l--;
            r++;
        }
    }

    for (let i = 0; i < n; i++) {
        expand(i, i);
        expand(i, i + 1);
    }
    console.log(distinct.size);
}

main();
