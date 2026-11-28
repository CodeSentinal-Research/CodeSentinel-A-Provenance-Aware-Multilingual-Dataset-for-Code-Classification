// P001490 - Count Binary Substrings
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    let prev = 0, cur = 1, ans = 0;
    for (let i = 1; i < s.length; i++) {
        if (s[i] === s[i - 1]) {
            cur++;
        } else {
            ans += Math.min(prev, cur);
            prev = cur;
            cur = 1;
        }
    }
    ans += Math.min(prev, cur);
    console.log(ans);
}

main();
