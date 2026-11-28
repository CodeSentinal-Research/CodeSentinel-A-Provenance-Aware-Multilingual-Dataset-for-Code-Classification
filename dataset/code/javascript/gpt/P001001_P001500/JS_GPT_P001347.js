// P001347 - Cryptarithmetic Puzzle
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const s1 = input[0], s2 = input[1], s3 = input[2];
    const letters = Array.from(new Set((s1 + s2 + s3).split("")));
    if (letters.length > 10) { console.log("NO"); return; }
    const assigned = new Map();
    const usedDigits = new Array(10).fill(false);
    function evalWord(w) {
        let val = 0;
        for (const c of w) val = val * 10 + assigned.get(c);
        return val;
    }
    function solve(idx) {
        if (idx === letters.length) {
            if (assigned.get(s1[0]) === 0 || assigned.get(s2[0]) === 0 || assigned.get(s3[0]) === 0) return false;
            return evalWord(s1) + evalWord(s2) === evalWord(s3);
        }
        const ch = letters[idx];
        for (let d = 0; d <= 9; d++) {
            if (!usedDigits[d]) {
                usedDigits[d] = true;
                assigned.set(ch, d);
                if (solve(idx + 1)) return true;
                usedDigits[d] = false;
                assigned.delete(ch);
            }
        }
        return false;
    }
    console.log(solve(0) ? "YES" : "NO");
}

main();
