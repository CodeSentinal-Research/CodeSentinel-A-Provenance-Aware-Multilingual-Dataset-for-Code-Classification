// P001455 - Longest Duplicate Substring
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    const n = s.length;
    let low = 1, high = n - 1;
    let best = "";

    function findDup(len) {
        const seen = new Set();
        for (let i = 0; i + len <= n; i++) {
            const sub = s.substring(i, i + len);
            if (seen.has(sub)) return sub;
            seen.add(sub);
        }
        return null;
    }

    while (low <= high) {
        const mid = (low + high) >> 1;
        const dup = findDup(mid);
        if (dup !== null) {
            best = dup;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    console.log(best);
}

main();
