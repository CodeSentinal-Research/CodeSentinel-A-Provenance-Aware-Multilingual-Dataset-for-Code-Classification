// P001578 - Count Windows With All Distinct Elements
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s = input[0];
    const k = parseInt(input[1], 10);
    if (k > 26 || s.length < k) {
        console.log(0);
        return;
    }
    const count = new Map();
    for (let i = 0; i < k; i++) {
        count.set(s[i], (count.get(s[i]) || 0) + 1);
    }
    let ans = 0;
    if (count.size === k) ans++;
    for (let i = k; i < s.length; i++) {
        count.set(s[i], (count.get(s[i]) || 0) + 1);
        const out = s[i - k];
        const c = count.get(out) - 1;
        if (c === 0) count.delete(out);
        else count.set(out, c);
        if (count.size === k) ans++;
    }
    console.log(ans);
}

main();
