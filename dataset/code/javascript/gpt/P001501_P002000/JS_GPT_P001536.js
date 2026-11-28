// P001536 - Minimum Window Substring
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s = input[0];
    const t = input[1];
    if (s.length < t.length) {
        console.log("");
        return;
    }
    const need = new Map();
    for (let i = 0; i < t.length; i++) {
        need.set(t[i], (need.get(t[i]) || 0) + 1);
    }
    const required = need.size;
    let l = 0, formed = 0;
    const window = new Map();
    let minLen = Infinity, start = 0;

    for (let r = 0; r < s.length; r++) {
        const c = s[r];
        window.set(c, (window.get(c) || 0) + 1);
        if (need.has(c) && window.get(c) === need.get(c)) {
            formed++;
        }
        while (l <= r && formed === required) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                start = l;
            }
            const leftC = s[l];
            window.set(leftC, window.get(leftC) - 1);
            if (need.has(leftC) && window.get(leftC) < need.get(leftC)) {
                formed--;
            }
            l++;
        }
    }
    console.log(minLen === Infinity ? "" : s.substring(start, start + minLen));
}

main();
