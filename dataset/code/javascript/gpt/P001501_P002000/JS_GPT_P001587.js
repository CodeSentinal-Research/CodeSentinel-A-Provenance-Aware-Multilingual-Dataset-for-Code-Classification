// P001587 - Number of Substrings Containing All Three Characters
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    const last = { 'a': -1, 'b': -1, 'c': -1 };
    let ans = 0;
    for (let i = 0; i < s.length; i++) {
        last[s[i]] = i;
        const minLast = Math.min(last['a'], last['b'], last['c']);
        ans += minLast + 1;
    }
    console.log(ans);
}

main();
