// P001493 - Shortest Distance to a Character
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s = input[0];
    const c = input[1];
    const n = s.length;
    const ans = new Array(n).fill(Infinity);
    let prev = -Infinity;
    for (let i = 0; i < n; i++) {
        if (s[i] === c) prev = i;
        ans[i] = i - prev;
    }
    prev = Infinity;
    for (let i = n - 1; i >= 0; i--) {
        if (s[i] === c) prev = i;
        ans[i] = Math.min(ans[i], prev - i);
    }
    console.log(ans.join(" "));
}

main();
