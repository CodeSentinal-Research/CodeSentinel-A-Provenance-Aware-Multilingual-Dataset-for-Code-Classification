// P001359 - Construct Lexicographically Largest Valid Sequence
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    const size = 2 * n - 1;
    const res = new Array(size).fill(0);
    const used = new Array(n + 1).fill(false);
    function backtrack(idx) {
        if (idx === size) return true;
        if (res[idx] !== 0) return backtrack(idx + 1);
        for (let num = n; num >= 1; num--) {
            if (used[num]) continue;
            if (num === 1) {
                res[idx] = 1;
                used[1] = true;
                if (backtrack(idx + 1)) return true;
                res[idx] = 0;
                used[1] = false;
            } else {
                if (idx + num < size && res[idx + num] === 0) {
                    res[idx] = num;
                    res[idx + num] = num;
                    used[num] = true;
                    if (backtrack(idx + 1)) return true;
                    res[idx] = 0;
                    res[idx + num] = 0;
                    used[num] = false;
                }
            }
        }
        return false;
    }
    backtrack(0);
    console.log(res.join(" "));
}

main();
