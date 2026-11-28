// P001352 - Split String into Descending Consecutive Values
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    function backtrack(idx, prev) {
        if (idx === s.length) return true;
        for (let i = idx + 1; i <= s.length; i++) {
            const val = BigInt(s.substring(idx, i));
            if (val === prev - 1n) {
                if (backtrack(i, val)) return true;
            }
        }
        return false;
    }
    for (let i = 1; i < s.length; i++) {
        const first = BigInt(s.substring(0, i));
        if (backtrack(i, first)) {
            console.log("YES");
            return;
        }
    }
    console.log("NO");
}

main();
